import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

n, p = I()
a = sorted(I())
m = 10 ** 9 + 7

used = set()
for gu in a:
	bad = False
	guy = gu
	while guy != 0:
		if guy % 2 == 1:
			guy = guy // 2
			if guy in used:
				bad = True
				break
		elif guy % 4 == 0:
			guy = guy // 4
			if guy in used:
				bad = True
				break
		else:
			break
	if not bad:
		used.add(gu)


add = [0] * 300000
pows = [0] * p
for guy in used:
	bits = len(bin(guy)) - 3
	add[bits] += 1

pows[0] = add[0]
if p == 1:
	print(pows[0])
	exit()
pows[1] = add[1] + pows[0]
tot = pows[0] + pows[1]
for i in range(2, p):
	pows[i] = (pows[i - 1] + pows[i - 2] + add[i]) % m
	tot = (tot + pows[i]) % m
print(tot)