import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

M = 10 ** 9 + 7
prec = [[(0, 0)] * 2000 for i in range(2001)]
for i in range(2000):
	prec[i + 1][i] = (i + 1, 0)
	for j in range(1, i + 1):
		x = prec[j - 1][i - 1]
		y = prec[j][i - 1]
		if x[1] < y[1]:
			xx = x[0] * pow(2, y[1] - x[1], M) % M
		else:
			xx = x[0]
		if x[1] > y[1]:
			yy = y[0] * pow(2, x[1] - y[1], M) % M
		else:
			yy = y[0]
		prec[j][i] = ((xx + yy) % M, max(x[1], y[1]) + 1)
#print(prec)
t, = I()
for _ in range(t):
	n, m, k = I()
	c, e = prec[m][n - 1]
	q = pow(2, e, M)
	qinv = pow(q, M - 2, M)
	print((c * k * qinv) % M)