t = input()
for tt in range(t):
	n = input()
	a = sorted(map(int, raw_input().split()))
	print min(a[i]-a[i-1] for i in range(1, n))