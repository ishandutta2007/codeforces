import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
import random

t, = I()
for _ in range(t):
	n, m, k, q = I()
	lastrow = {}
	lastcol = {}
	ops = []
	for i in range(q):
		a, b = I()
		a -= 1
		b -= 1
		ops.append((a, b))
		lastrow[a] = i
		lastcol[b] = i
	if len(lastrow) == n:
		everyrow = min(lastrow[guy] for guy in lastrow)
	else:
		everyrow = 0
	if len(lastcol) == m:
		everycol = min(lastcol[guy] for guy in lastcol)
	else:
		everycol = 0
	valid = 0
	for i in range(q):
		a, b = ops[i]
		if (lastrow[a] == i and i >= everycol) or (lastcol[b] == i and i >= everyrow):
			valid += 1
	print(pow(k, valid, 998244353))