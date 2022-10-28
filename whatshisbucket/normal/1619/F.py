import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t,=I()
for _ in range(t):
	n, m, k = I()
	players = [i + 1 for i in range(n)]
	big = n % m
	sml = m - big
	for i in range(k):
		start = (n * i) // k
		ind = start
		for j in range(big):
			out = [str(n // m + 1)]
			for l in range(n // m + 1):
				out.append(str(players[ind]))
				ind = (ind + 1) % n
			print(' '.join(out))
		for j in range(sml):
			out = [str(n // m)]
			for l in range(n // m):
				out.append(str(players[ind]))
				ind = (ind + 1) % n
			print(' '.join(out))