l = input()
s = raw_input()
n = input()
a = []
def match(s, t):
	call = set([])
	miss = set([])
	for i in range(l):
		if s[i] == t[i]:
			call.add(t[i])
			pass
		elif s[i] == '*':
			miss.add(t[i])
		else:
			return False
	if len(call & miss) == 0:
		return True
	else:
		return False

v = set(map(chr, range(97, 123))) - set(s)
for i in range(n):
	t = raw_input()
	if match(s, t):
		v = v & set(t)

print len(v)