t = int(input())
for i in range(t):
	n,m=map(int, input().split())
	same = {i:set() for i in range(n)}
	diff = {i:set() for i in range(n)}
	for i in range(m):
		i,j,c = input().split()
		i,j =int(i)-1,int(j)-1
		if c == "crewmate":
			same[i].add(j)
			same[j].add(i)
		else:
			diff[i].add(j)
			diff[j].add(i)
	inds = [-1]*n
	bad = False
	total = 0
	for i in range(n):
		if bad:
			break
		if inds[i] == -1:
			colors = {i:1}
			layer = [i]
			while layer != []:
				newlayer = []
				for guy in layer:
					for neighbor in same[guy]:
						if neighbor not in colors:
							colors[neighbor] = colors[guy]
							newlayer.append(neighbor)
							inds[neighbor] = 1
						elif colors[neighbor] == - colors[guy]:
							bad = True
					for neighbor in diff[guy]:
						if neighbor not in colors:
							colors[neighbor] = -colors[guy]
							newlayer.append(neighbor)
							inds[neighbor] = 1
						elif colors[neighbor] == colors[guy]:
							bad = True
				layer = newlayer
			pos = 0
			neg = 0
			for guy in colors:
				if colors[guy] == 1:
					pos += 1
				else:
					neg += 1
			total += max(pos, neg)
	if bad:
		print(-1)
	else:
		print(total)