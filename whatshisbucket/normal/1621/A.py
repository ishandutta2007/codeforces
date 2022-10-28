import sys
I = lambda:map(int, sys.stdin.readline().split())

t, = I()
for _ in range(t):
	n, k = I()
	if n < 2 * k - 1:
		print(-1)
	else:
		for i in range(n):
			out = ['.'] * n
			if i % 2 == 0 and i < 2 * k:
				out[i] = 'R'
			print(''.join(out))