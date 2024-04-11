t = int(input())
def solve(n, m, x1, y1, x2, y2, w, h):
	z = 10 ** 9
	if x2 - x1 + w <= n:
		z = min(z, max(w - x1, 0))
	if y2 - y1 + h <= m:
		z = min(z, max(h - y1, 0))
	return z

for tt in range(t):
	n, m = map(int, input().split())
	x1, y1, x2, y2 = map(int, input().split())
	w, h = map(int, input().split())
	z = min(solve(n, m, x1, y1, x2, y2, w, h), solve(n, m, n - x2, y1, n - x1, y2, w, h),
			solve(n, m, x1, m - y2, x2, m - y1, w, h), solve(n, m, n - x2, m - y2, n - x1, m - y1, w, h))
	if z == 10 ** 9:
		z = -1
	print(z)