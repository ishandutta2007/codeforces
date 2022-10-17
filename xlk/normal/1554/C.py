t = int(input())
for tt in range(t):
	n, m = map(int, input().split())
	m += 1
	z = 0
	for i in range(31)[::-1]:
		if n >> i & 1:
			m -= 1 << i
		else:
			if m >= 1 << i:
				m -= 1 << i
				z += 1 << i
	print(z)