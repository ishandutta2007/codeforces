import sys
import time
inpu = sys.stdin.readline
prin = sys.stdout.write

n = int(inpu())
if n == 1:
	a = int(inpu())
	inpu()
	q = int(inpu())
	for _ in range(q):
		print(abs(a - int(inpu())))
	exit()
a = list(map(int, inpu().split()))
printing = False
#if n == 200000 and a[:4] == [1000000, 1, 1000000, 1000000]:
#	printing = True
b = list(map(int, inpu().split()))
diff = [0] * n
times = [0] * n
hits = [0] * n
for i in range(1, n):
	needed = b[i] - a[i] - diff[i]
	times[i] = needed
	for j in range(i, n, i + 1):
		diff[j] += needed
		hits[j] += 1
if printing:
	print('ok')
#print(hits)
#print(diff)
#print(times)
cubes = [8, 27, 125, 343, 1331, 2197, 4913, 6859, 12167, 24389, 29791, 50653, 68921, 79507, 103823, 148877]
odd = [1, 7, 31]
even = [3, 15, 63]

odds = []
evens = []
for i in range(1, n):
	if hits[i] in odd:
		if hits[i] > 1:
			bad = False
			for cube in cubes:
				if (i + 1) % cube == 0:
					bad = True
					break
			if bad:
				continue
		odds.append(i)
	elif hits[i] in even:
		bad = False
		for cube in cubes:
			if (i + 1) % cube == 0:
				bad = True
				break
		if not bad:
			evens.append(i)
#print(odds, evens)
if printing:
	print('ok')
start = []
for guy in odds:
	start.append(times[guy])
for guy in evens:
	start.append(- times[guy])
if printing:
	print('ok')

noc = sum(abs(guy) for guy in times)
start.sort()
f = len(start)
#print(start)
just = sum(abs(guy) for guy in start)
#print(just, noc)
changes = []
changes.append((start[0], sum(abs(guy - start[0]) for guy in start)))
for i in range(1, f):
	if start[i] != start[i - 1]:
		changes.append((start[i], changes[-1][-1] - (f - 2 * i) * (start[i] - start[i - 1])))
l = len(changes)
if printing:
	print('ok')
#print(changes)
q = int(inpu())
for _ in range(q):
	b1 = int(inpu())
	change = b1 - a[0]
	if change < changes[0][0]:
		if printing:
			print('ok', 1)
		diff = changes[0][0] - change
		cost = changes[0][1] + diff * f
		print(noc + cost - just + abs(change))
	elif change >= changes[-1][0]:
		if printing:
			print('ok', 2)
		diff = change - changes[-1][0]
		cost = changes[-1][1] + diff * f
		print(noc + cost - just + abs(change))
	else:
		if printing:
			print('ok', 3)
		sml = 0
		big = l - 1
		while big - sml > 1:
			ind = (sml + big) // 2
			if printing:
				print('ok', 4, ind)
			if change > changes[ind][0]:
				sml = ind
			elif change < changes[ind][0]:
				big = ind
			else:
				sml = ind
				big = ind + 1
		cost = changes[sml][1] + (change - changes[sml][0]) * (changes[big][1] - changes[sml][1]) // (changes[big][0] - changes[sml][0])
		print(noc + cost - just + abs(change))