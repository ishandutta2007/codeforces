import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	I()
	n, d = I()
	a = I()
	rests = [a[0] - 1]
	for i in range(n - 1):
		rests.append(a[i + 1] - a[i] - 1)
	extra = d - a[-1]
	m = min(rests)
	if rests.count(m) > 2:
		print(m)
		continue
	elif rests.count(m) == 2:
		ind = rests.index(m)
		if rests[ind + 1] != m:
			print(m)
			continue
		rests.remove(m)
		rests[ind] += m + 1
		print(min(min(rests), max((max(rests) - 1) // 2, extra - 1)))
		continue
	ind = rests.index(m)
	if ind == 0:
		rests.remove(m)
		rests[ind] += m + 1
		sml2 = min(min(rests), max((max(rests) - 1) // 2, extra - 1))
		print(sml2)
		continue
	alt1 = rests[:]
	alt1.remove(m)
	alt1[ind - 1] += m + 1
	sml1 = min(min(alt1), max((max(alt1) - 1) // 2, extra - 1))

	alt2 = rests[:]
	alt2.remove(m)
	if ind == len(alt2):
		extra += m + 1
	else:
		alt2[ind] += m + 1
	sml2 = min(min(alt2), max((max(alt2) - 1) // 2, extra - 1))
	print(max(sml1, sml2))