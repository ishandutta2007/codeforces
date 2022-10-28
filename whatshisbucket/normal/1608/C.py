import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	b = list(map(int, inpu().split()))
	tups = []
	tups1 = []
	for i in range(n):
		tups.append((a[i], b[i], i))
		tups1.append((b[i], a[i], i))
	tups.sort(reverse = True)
	tups1.sort(reverse = True)
	unseen = set()
	unseen1 = set()
	for i in range(n):
		if tups[i][2] in unseen1:
			unseen1.remove(tups[i][2])
		else:
			unseen.add(tups[i][2])
		if tups1[i][2] in unseen:
			unseen.remove(tups1[i][2])
		else:
			unseen1.add(tups1[i][2])
		if len(unseen) == 0:
			break
	out = [0] * n
	for j in range(i + 1):
		out[tups[j][2]] = 1
	print(''.join(str(guy) for guy in out))