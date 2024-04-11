t = int(input())
for tt in range(t):
	n, c = input().split()
	n = int(n)
	s = input()
	s = s + s
	z = l = 0
	for i in s[::-1]:
		l += 1
		if i == 'g':
			l = 0
		if i == c:
			z = max(z, l)
	print(z)