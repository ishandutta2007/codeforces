t = int(input())
for tt in range(t):
	n = int(input())
	a = [input() for i in range(n)]
	s = set(a)
	z = ''
	for i in range(n):
		for j in range(1, len(a[i])):
			if a[i][:j] in s and a[i][j:] in s:
				z += '1'
				break
		else:
			z += '0'
	print(z)