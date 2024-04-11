t = input()
def F(s):
	r = set()
	s = list(s)
	for i in range(len(s)):
		c = s[i]
		for j in 'abcdefghijklmnopqrstuvwxyz':
			s[i] = j
			r.add(''.join(s))
		s[i] = c
	return r
for tt in range(t):
	n, m = map(int, raw_input().split())
	a = set()
	for i in range(n):
		if i == 0:
			a = F(raw_input())
		else:
			a = a & F(raw_input())
	if len(a) == 0:
		print -1
	else:
		print list(a)[0]