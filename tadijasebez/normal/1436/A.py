t = int(input())
for tc in range(t):
	n, m = map(int, input().split())
	a = map(int, input().split())
	ans = sum(i for i in a)
	print("YES" if ans == m else "NO")