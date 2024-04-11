# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	a, b, c, d = I()
	s = sys.stdin.readline().strip()
	n = len(s)
	As = s.count('A')
	num = a + c + d
	if As != num:
		print('NO')
		continue
	both = []
	aa = []
	bb = []
	curr = s[0]
	l = 0
	for i in range(n):
		#print(l)
		if s[i] != curr:
			l += 1
			curr = s[i]
		else:
			if l > 1:
				if l % 2:
					both.append(l)
				elif start == 'A':
					aa.append(l)
				else:
					bb.append(l)
			l = 1
			start = s[i]
	if l > 1:
		if l % 2:
			both.append(l)
		elif start == 'A':
			aa.append(l)
		else:
			bb.append(l)
	#print(both, aa, bb)
	ab = sum(guy // 2 for guy in aa)
	ba = sum(guy // 2 for guy in bb)
	either = sum(guy // 2 for guy in both)
	#print(ab, ba, either)
	if ab >= c and ba >= d:
		print('YES')
	elif ab < c and ba < d:
		if either >= c - ab + d - ba:
			print('YES')
		else:
			print('NO')
	elif ab < c:
		l = sorted(bb, reverse = True)
		for guy in l:
			if ba == d:
				break
			add = guy // 2 - 1
			change = min(add, ba - d - 1)
			ab += change
			ba -= change + 1
		if ab < c and either < c - ab:
			print('NO')
		else:
			print('YES')
	else:
		l = sorted(aa, reverse = True)
		for guy in l:
			if ab == c:
				break
			add = guy // 2 - 1
			change = min(add, ab - c - 1)
			ba += change
			ab -= change + 1
		if ba < d and either < d - ba:
			print('NO')
		else:
			print('YES')