t = int(input())
for tt in range(t):
	n, m = map(int, input().split())
	a = list(map(int, input().split()))
	if len(set(a)) == 1 and m in a:
		print(0)
	elif sum(a) == n * m or m in a:
		print(1)
	else:
		print(2)