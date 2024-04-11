n = input()
a = map(int, raw_input().split())
z = 0
for i in range(n):
	for j in range(i):
		z ^= a[i] < a[j]
m = input()
for i in range(m):
	l, r = map(int, raw_input().split())
	z ^= (r - l + 1) / 2 % 2
	print ['even', 'odd'][z]