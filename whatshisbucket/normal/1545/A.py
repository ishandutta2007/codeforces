t = int(input())
count = [[0, 0] for i in range(10 ** 5)]
for _ in range(t):
	n = int(input())
	a = list(map(int, input().split()))
	a = [(a[i], i) for i in range(n)]
	a.sort()
	for x, i in a:
		count[x - 1][i % 2] += 1
	i = 0
	bad = False
	while i < n:
		val = a[i][0]
		tot = count[val - 1][0] + count[val - 1][1]
		mod = i % 2
		if tot % 2 == 0:
			if count[val - 1][0] != count[val - 1][1]:
				bad = True
				print("NO")
				break
		else:
			if count[val - 1][mod] != count[val - 1][1 - mod] + 1:
				bad = True
				print("NO")
				break
		i += tot
	for x, i in a:
		count[x - 1] = [0, 0]
	if not bad:
		print("YES")