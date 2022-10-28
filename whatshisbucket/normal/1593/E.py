t=int(input())
for _ in range(t):
	empty = input()
	ni,k = map(int,input().split())
	neighbors = {i:[] for i in range(ni)}
	for i in range(ni-1):
		v,w = map(int,input().split())
		neighbors[v-1].append(w-1)
		neighbors[w-1].append(v-1)
	time = {}
	layer = []
	for i in range(ni):
		if len(neighbors[i]) <= 1:
			time[i] = 1
			layer.append(i)
	dist = 2
	while len(time) < ni and dist <= k:
		newlayer = set()
		for v in layer:
			for n in neighbors[v]:
				if n not in newlayer and n not in time:
					alive = 0
					for nn in neighbors[n]:
						if nn not in time or time[nn] == dist:
							alive+=1
							if alive == 2:
								break
					if alive < 2:
						newlayer.add(n)
						time[n] = dist
		dist += 1
		layer = newlayer
	print(ni-len(time))