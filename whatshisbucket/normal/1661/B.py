# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, = I()
a = I()
layer = [0]
distances = [-1] * 32768
distances[0] = 0
i = 1
while layer != []:
	newlayer = []
	for guy in layer:
		if distances[guy - 1] == -1:
			newlayer.append(guy - 1)
			distances[guy - 1] = i
		if guy % 2 == 0:
			if distances[guy // 2] == -1:
				newlayer.append(guy // 2)
				distances[guy // 2] = i
			if distances[guy // 2 + 16384] == -1:
				newlayer.append(guy // 2 + 16384)
				distances[guy // 2 + 16384] = i
	layer = newlayer
	i += 1
print(*[distances[guy] for guy in a])