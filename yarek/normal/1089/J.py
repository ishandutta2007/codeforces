from collections import defaultdict

n = int(input())
reserved = set(input().split())

m = int(input())
lines = [ input().split('#')[0].split() for _ in range(m) ]

tokens = sum(lines, [])

def isword(t):
	return not t[0].isdigit() and all(c.isalnum() or c == '_' or c == '$' for c in t)

def ok(t):
	return t in reserved or t.isdigit() or isword(t)
	
def tokenize(t):
	res = []
	i = 0
	n = len(t)
	while i < n:
		for j in range(n, i, -1):
			if ok(t[i:j]):
				res.append(t[i:j])
				i = j
				break
	return res
	
tokens = sum(map(tokenize, tokens), [])

dig = 1
k = 0
limit = 26

def next_token():
	global dig, k, limit
	if k == limit:
		k = 0
		dig += 1
		limit = 26 ** dig
	w = []
	l = k
	for _ in range(dig):
		w += chr(ord('a') + l % 26)
		l //= 26
	w = ''.join(reversed(w))
	k += 1
	if w in reserved:
		return next_token()
	return w
		
dc = defaultdict(next_token)

def replace(t):
	if t in reserved or t.isdigit():
		return t
	return dc[t]

def can_append(a, b, bg):
	if len(a) == 0:
		return True
	#if a not in reserved and b not in reserved:
	#	return False
	for i, s in enumerate(bg):
		if i + 1 != len(bg) and len(a) - s > 21:
			continue
		for i in range(len(b)):
			if ok(a[s:] + b[:i+1]):
				#print(a, b, a[s:] + b[:i+1])
				return False
	#print('can append', a, b)
	return True	

res = ['']
begin = []
for t in map(replace, tokens):
	if not can_append(res[-1], t, begin):
		res.append('')
		begin = []
	begin.append(len(res[-1]))
	res[-1] += t

print(' '.join(res))