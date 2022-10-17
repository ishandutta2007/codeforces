def F(s, t):
	z = 0
	for i in range(len(s)):
		z += abs(ord(s[i]) - ord(t[i]))
	return z

for t in range(int(input())):
	n, m = map(int, input().split())
	a = []
	for i in range(n):
		a.append(input())
	z = 1e9
	for i in range(n):
		for j in range(i):
			z = min(z, F(a[i], a[j]))
	print(z)