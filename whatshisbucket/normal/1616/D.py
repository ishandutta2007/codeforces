import sys
I=lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	x, = I()
	dp = [[0, 0, 0] for i in range(n)]
	dp[0] = [0, 1, 0]
	for i in range(1, n):
		dp[i][0] = max(dp[i - 1])
		dp[i][1] = dp[i - 1][0] + 1

		best = 0
		if a[i] + a[i - 1] >= 2 * x:
			best = dp[i - 1][1] + 1
			if i > 1 and a[i] + a[i - 1] + a[i - 2] >= 3 * x:
				best = max(best, dp[i - 1][2] + 1)
		dp[i][2] = best

	print(max(dp[-1]))