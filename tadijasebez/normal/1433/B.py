t = int(input())
for tc in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	l, r = min(i for i in range(n) if a[i] == 1), max(i for i in range(n) if a[i] == 1)
	cnt = sum(a)
	print(r-l+1-cnt)