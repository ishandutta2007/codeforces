import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	n, = I()
	s = input()
	prev = 'a'
	curr = s[-1]
	reflect = None
	for i in range(n - 1, -1, -1):
		if s[i] != curr:
			prev = curr
			curr = s[i]
			if curr < prev:
				reflect = i
	if reflect is None:
		if n == 1:
			print(s + s)
		elif s[0] == s[1]:
			print(s[:2])
		else:
			print(s + s[::-1])
	else:
		if s[0] == s[1]:
			reflect = 0
		out = [s[:reflect + 1]]
		i = reflect
		while i >= 0:
			out.append(s[i])
			i -= 1
		print(''.join(out))