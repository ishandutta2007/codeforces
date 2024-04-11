import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	suffbig = [0] * n
	suffbig[-1] = (a[-1], n - 1)
	for i in range(n - 2, -1, -1):
		if a[i] > suffbig[i + 1][0]:
			suffbig[i] = (a[i], i)
		else:
			suffbig[i] = suffbig[i + 1]
	suffdiff = [0] * n
	suffdiff[-1] = suffdiff[-2] = None
	suffdiff[-3] = (a[-2] - a[-1], n - 2, n - 1)
	for i in range(n - 4, -1, -1):
		if a[i + 1] - suffbig[i + 2][0] < suffdiff[i + 1][0]:
			suffdiff[i] = (a[i + 1] - suffbig[i + 2][0], i + 1, suffbig[i + 2][1])
		else:
			suffdiff[i] = suffdiff[i + 1]
	out = []
	for i in range(n - 2):
		if suffdiff[i][0] < a[i] or (i > 0 and a[i] < a[i - 1]):
			out.append((i, suffdiff[i][1], suffdiff[i][2]))
			a[i] = suffdiff[i][0]
	if a == sorted(a):
		print(len(out))
		for i, j, k in out:
			print(i + 1, j + 1, k + 1)
	else:
		print(-1)