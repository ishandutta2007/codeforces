n, m = map(int, input().split())
a = [list(map(int, input().split()))for i in range(n)]
row = 'row'
col = 'col'
if n > m:
	row, col = col, row
	n, m = m, n
	a = list(map(list, zip(*a)))
z = []
for i in range(n):
	x = min(a[i])
	for j in range(m):
		a[i][j] -= x
	z += [(row, i + 1)] * x
for i in range(1, n):
	if a[i] != a[i - 1]:
		print('-1')
		exit()
for j in range(m):
	z += [(col, j + 1)] * a[0][j]
print(len(z))
for i in z:
	print(*i)