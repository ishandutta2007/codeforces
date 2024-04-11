n, k = map(int, raw_input().split())
def go(l, r, x):
	global k
	if k == 0 or l == r - 1:
		for i in range(r - l):
			print x + i,
	else:
		k -= 2
		m = (l + r) / 2
		go(l, m, x + r - m)
		go(m, r, x)

if k % 2 == 0 or k > 2 * n:
	print -1
else:
	k -= 1
	go(0, n, 1)