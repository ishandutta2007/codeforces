n, m = map(int, raw_input().split())
c = 0
while n < m:
	c += m % 2 + 1
	m = (m + 1) / 2
c += n - m
print c