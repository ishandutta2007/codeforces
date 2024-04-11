t = int(input())
for tt in range(t):
	n = int(input())
	s = input()
	a = []
	z = 0
	for i in range(n):
		if s[i] == 'L':
			z += i
			a.append(n - i - 1 - i)
		else:
			z += n - i - 1
			a.append(i - (n - i - 1))
	a.sort(reverse=True)
	b = []
	for i in range(n):
		z += max(a[i], 0)
		b.append(z)
	print(*b)