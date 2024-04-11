import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

def reverse(n):
	return math.ceil((2*n)**0.5)

t = int(input())
for _ in range(t):
	n = int(input())
	print('?', 1, n)
	tot = int(input())
	left = 1
	right = n
	mid = (left + right) // 2
	while True:
		print('?', left, mid)
		inv = int(input())
		if inv == 0:
			left = mid
			mid = (left + right) // 2
		elif inv == tot:
			right = mid
			mid = (left + right) // 2
		else:
			break
	invl = inv
	print('?', mid + 1, right)
	invr = int(input())
	missing = tot - invl - invr
	if missing == 0:
		m = mid + 1
		r = m + reverse(invr) - 1
		l = m - reverse(invl)
		print('!', l, m, r)
		continue
	print('?', mid, right)
	oinvr = int(input())
	diff = oinvr - invr
	if invr == diff * (diff - 1) // 2:
		r = mid + diff
		other = missing // diff
		m = mid + 1 - other
		totr = other + diff
		linv = tot - totr * (totr - 1) // 2
		#print(linv, other, diff,  missing, mid, totr)
		l = m - reverse(linv)
		print('!', l, m, r)
	else:
		print('?', left, mid + 1)
		oinvl = int(input())
		diff = oinvl - invl
		l = mid - diff + 1
		other = missing // diff
		m = mid + other + 1
		totl = other + diff
		rinv = tot - totl * (totl - 1) // 2
		r = m + reverse(rinv) - 1
		print('!', l, m, r)