
def calc(H, x):
	if (x <= H):
		return x * (x + 1) / 2
	else:
		if ((x - H) % 2 == 0):
			tmp = H + (x - H) / 2
			return (H + tmp) * (tmp - H + 1) / 2 + tmp * (tmp - 1) / 2
		else:
			tmp = H + (x - H) / 2
			return (H + tmp) * (tmp - H + 1) / 2 + tmp * (tmp + 1) / 2

n, H = map(int, raw_input().split())
l, r = 0, 1000000000000000000L
while (l < r - 1):
	mid = (l + r) / 2
	# print mid, calc(H, mid)
	if (calc(H, mid) >= n):
		r = mid
	else:
		l = mid
print r