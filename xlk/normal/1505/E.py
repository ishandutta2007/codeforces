s = []
n, m = map(int, input().split())
for i in range(n):
	s.append(input())
x, y = 0, 0
z = 0
if s[x][y] == '*':
	z += 1
while x < n - 1 or y < m - 1:
	if x == n - 1:
		y += 1
	elif y == m - 1:
		x += 1
	elif s[x][y + 1] == '*':
		y += 1
	elif s[x + 1][y] == '*':
		x += 1
	else:
		y += 1
	if s[x][y] == '*':
		z += 1
print(z)