# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]


t, = I()
for _ in range(t):
	n, m = I()
	words = []
	for i in range(n):
		words.append(input())
	sml = float('inf')
	for i in range(n):
		for j in range(i + 1, n):
			word1 = words[i]
			word2 = words[j]
			cost = 0
			for k in range(m):
				cost += abs(ord(word1[k]) - ord(word2[k]))
			sml = min(sml, cost)
	print(sml)