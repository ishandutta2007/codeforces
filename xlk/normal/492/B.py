n, l = map(int, raw_input().split())
a = map(int, raw_input().split())
a = sorted(a)
z = max(a[0], l - a[-1]) * 2
for i in range(1, n):
	z = max(z, a[i] - a[i - 1])
print z / 2.0