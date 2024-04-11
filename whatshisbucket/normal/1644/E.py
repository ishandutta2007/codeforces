import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
import random

t, = I()
for _ in range(t):
	n, = I()
	s = input()
	r = s.count('R')
	d = s.count('D')
	if r == 0 or d == 0:
		print(n)
		continue
	rleft = n - 1 - r
	dleft = n - 1 - d
	cumr = [0]
	cumd = [0]
	for i in range(len(s)):
		if s[i] == 'R':
			add = 1
		else:
			add = 0
		cumr.append(cumr[-1] + add)
		cumd.append(cumd[-1] + 1 - add)
	beforer = cumr.index(1) - 1
	befored = cumd.index(1) - 1
	tot = 0

	i = 0
	totmind = 0
	while i < 2 * n - 1:
		if i - rleft < beforer:
			newi = min(2 * n - 1, beforer + rleft)
			totmind += (newi - i) * beforer
			totmind -= beforer * (beforer + 1) // 2 
			i = newi
			#print(totmind)
		if i - rleft >= len(s):
			val = cumd[-1]
			big = 2 * n - 2 - rleft - len(s)
			x = (big + 1) * val + big * (big + 1) // 2
			#print(x)
			totmind += x
			break
		else:
			#print(i, cumd[i - rleft])
			totmind += cumd[i - rleft]
			i += 1

	i = 0
	totminr = 0
	while i < 2 * n - 1:
		if i - dleft < befored:
			newi = min(2 * n - 1, befored + dleft)
			totminr += (newi - i) * befored
			totminr -= befored * (befored + 1) // 2
			#print(totminr)
			i = newi
		if i - dleft >= len(s):
			val = cumr[-1]
			big = 2 * n - 2 - dleft - len(s)
			x = (big + 1) * val + big * (big + 1) // 2
			#print(x)
			totminr += x
			break
		else:
			#print(i, cumr[i - dleft])
			totminr += cumr[i - dleft]
			i += 1

	totmaxd = (2 * n - 1) * (2 * n - 2) // 2 - totminr
	tot = totmaxd - totmind + 2 * n - 1

	# for i in range(2 * n - 1):
	# 	if i < beforer:
	# 		mind = i
	# 	else:
	# 		mind = cumd[min(max(i - rleft, beforer), len(s))]
	# 		if i - rleft > len(s):
	# 			mind += i - rleft - len(s)
	# 	if i < befored:
	# 		minr = i
	# 	else:
	# 		minr = cumr[min(max(i - dleft, befored), len(s))]
	# 		if i - dleft > len(s):
	# 			minr += i - dleft - len(s)
	# 	maxd = i - minr
	# 	tot += maxd - mind + 1
	# 	print(i, maxd - mind + 1)
	print(tot)