t = int(input())
for _ in range(t):
	n = int(input())
	p = list(map(int, input().split()))
	if p[0] == n or p[-1] == n:
		print(' '.join(str(guy) for guy in p[::-1]))
	else:
		print(-1)