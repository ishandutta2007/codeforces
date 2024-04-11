t = int(input())
for tt in range(t):
	n, k = map(int, input().split())
	print(-(-n // k * k // n))