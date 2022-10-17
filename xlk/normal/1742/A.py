t = int(input())
for tt in range(t):
	a = list(map(int, input().split()))
	if sum(a) == max(a) * 2:
		print('YES')
	else:
		print('NO')