T = int(input())
for test in range(T):
	n = int(input())
	a = [int(i) for i in input().split()]
	cnt = [0] * (n + 1)
	res = 0
	for i in range(n):
		extra = max(0, a[i] - 1 - cnt[i])
		res += extra
		cnt[i] += extra
		for j in range(n - 1, i, -1):
			if abs(i - j) <= a[i]:
				cnt[j] += 1
		cnt[i + 1] += cnt[i] - a[i]
	print(res)