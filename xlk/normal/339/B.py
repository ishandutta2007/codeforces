m, n = map(int, raw_input().split())
a = [1] + map(int, raw_input().split())
z = 0
for i in range(n):
	if a[i + 1] >= a[i]:
		z += a[i + 1] - a[i]
	else:
		z += a[i + 1] - a[i] + m
print z