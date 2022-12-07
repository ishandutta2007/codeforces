T = int(input())
for test in range(T):
	n, u, v = [int(i) for i in input().split()]
	A = [int(i) for i in input().split()]
	ans = v + min(u, v)
	for i in range(1, n):
		d = abs(A[i] - A[i - 1])
		if d == 1:
			ans = min(ans, min(u, v))
		if d > 1:
			ans = 0
	print(ans)