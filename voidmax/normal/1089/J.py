def main():
	t = int(input())
	reserved = set(input().split())

	lines = int(input())
	code = ''
	for i in range(lines):
		code += input() + '\n'

	def is_word(suspect):
		if suspect[0].isdigit(): return False
		for x in suspect:
			if (not x.isalpha()) and (not x in {'_', '$'}) and (not x.isdigit()):
				return False
		return True

	def is_token(suspect):
		if suspect in reserved: return True
		if is_word(suspect): return True
		if suspect.isdigit(): return True
		return False

	def remove_comments(code):
		rez = ''
		state = None
		for i in range(len(code)):
			if code[i] == '#':
				state = 'comment'
			elif code[i] == '\n':
				rez += code[i]
				state = None
			else:
				if state != 'comment':
					rez += code[i]
		return rez

	code = remove_comments(code)
	code = code.replace('\n', ' ')

	def split(code):
		tokens = []
		i = 0
		while i < len(code):
			if code[i] == ' ':
				i += 1
				continue
			for l in range(min(len(code), 90), 0, -1):
				if is_token(code[i:i + l]):
					tokens.append(code[i:i + l])
					i += l
					break
			else:
				return []
		return tokens

	def minmize(tokens):
		all = []
		pref = [chr(i + ord('a')) for i in range(26)]
		all.extend(pref)
		for ext in range(3):
			cur = []
			for i in range(26):
				for p in pref:
					cur.append(p + chr(i + ord('a')))
			cur.sort()
			all.extend(cur)
			pref = cur[::]

		all.reverse()
		zip = dict()
		for i in range(len(tokens)):
			if not tokens[i] in reserved and not tokens[i][0].isdigit():
				if not zip.get(tokens[i], None):
					while all[-1] in reserved:
						all.pop()
					zip[tokens[i]] = all[-1]
					all.pop()
				tokens[i] = zip[tokens[i]]
		return tokens

	tokens = (minmize(split(code)))

	def cmp(a, b):
		if len(a) != len(b): return False
		for i in range(len(a)):
			if a[i] != b[i]: return False
		return True

	final = []
	for i in range(len(tokens)):
		p = 0
		for j in range(i - 1, -1, -1):
			if len(''.join(tokens[j:i + 1])) > 23:
				p = j
				break

		st = ''
		if i and (not cmp(tokens[p:i + 1], split(''.join(final[p:i]) + tokens[i]))):
			st += ' '
		final.append(st + tokens[i])
	print(''.join(final))
main()