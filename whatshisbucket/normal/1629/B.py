import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	l, r, k = I()
	odd = (r - l + 1) // 2
	if r % 2 == 1 and l % 2 == 1:
		odd += 1
	if r - l == 0 and l > 1:
		print('YES')
		continue
	if k >= odd:
		print('YES')
	else:
		print('NO')