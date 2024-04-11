t = int(input())
for tt in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	for i in range(n):
		a[i] -= 1
	z = 0
	while len(a) > 1:
		b = []
		for i in range(0, len(a), 2):
			if a[i] // 2 != a[i + 1] // 2:
				z = -1e9
			if a[i] > a[i + 1]:
				z += 1
			b.append(a[i] // 2)
		a = b
	if z < 0:
		z = -1
	print(z)