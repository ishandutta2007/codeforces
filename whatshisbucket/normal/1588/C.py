import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

def find(a, l, r):
	if r - l == 1:
		if a[l] == 0:
			return 1
		else:
			return 0
	if r - l == 2:
		tot = 0
		if a[l] == 0:
			tot += 1
		if a[l + 1] == 0:
			tot += 1
		if a[l] == a[l + 1]:
			tot += 1
		return tot
	mid = (l + r) // 2
	left = find(a, l, mid)
	right = find(a, mid, r)
	altleft = {}
	altright = {}
	rsum = 0
	diff = 0
	smleven = float('inf')
	bigodd = -smleven
	for i in range(mid, r):
		if diff % 2 == 0:
			if rsum < smleven:
				smleven = rsum
		else:
			if rsum > bigodd:
				bigodd = rsum
		diff += 1
		if diff % 2 == 0:
			rsum += a[i]
		else:
			rsum -= a[i]
		if diff % 2 == 0 and rsum <= smleven and rsum >= bigodd:
			if rsum in altright:
				altright[rsum] += 1
			else:
				altright[rsum] = 1
		elif diff % 2 == 1 and rsum <= smleven and rsum >= bigodd and a[i] <= a[i - 1]:
			if rsum in altright:
				altright[rsum] += 1
			else:
				altright[rsum] = 1
	lsum = 0
	diff = 0
	bigeven = -float('inf')
	smlodd = -bigeven
	for i in range(mid - 1, l - 1, -1):
		if diff % 2 == 0:
			if lsum > bigeven:
				bigeven = lsum
		else:
			if lsum < smlodd:
				smlodd = lsum
		diff += 1
		if diff % 2 == 1:
			lsum += a[i]
		else:
			lsum -= a[i]
		if diff % 2 == 0 and lsum <= smlodd and lsum >= bigeven:
			if lsum in altleft:
				altleft[lsum] += 1
			else:
				altleft[lsum] = 1
		elif diff % 2 == 1 and lsum <= smlodd and lsum >= bigeven and a[i] <= a[i + 1]:
			if lsum in altleft:
				altleft[lsum] += 1
			else:
				altleft[lsum] = 1
	tot = 0
	#print(l, r)
	#print(altleft)
	#print(altright)
	for guy in altleft:
		if -guy in altright:
			tot += altleft[guy] * altright[-guy]
	#print(l, r, tot, left, right)
	return tot + left + right


t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int, inpu().split()))
	prin(str(find(a, 0, n)))
	prin('\n')