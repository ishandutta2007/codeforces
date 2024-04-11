# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda: [*map(int, read.readline().split())]

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def solve(s):
	l = len(s)
	if l <= 10:
		tot = 0
		for i in range(l):
			plus = 0
			minus = 0
			for j in range(i, l):
				if s[j] == '+':
					plus += 1
				else:
					minus += 1
				if minus >= plus and (minus - plus) % 3 == 0:
					tot += 1
		return tot
	else:
		x = s[:l//2]
		y = s[l//2:]
		xx = [[], [], []]
		yy = [[], [], []]
		plus = 0
		minus = 0
		for char in x[::-1]:
			if char == '+':
				plus += 1
			else:
				minus += 1
			xx[(minus - plus) % 3].append(minus - plus)
		plus = 0
		minus = 0
		for char in y:
			if char == '+':
				plus += 1
			else:
				minus += 1
			yy[(minus - plus) % 3].append(minus - plus)
		for i in range(3):
			xx[i].sort(reverse = True)
			yy[i].sort(reverse = True)
		tot = 0
		for i in range(3):
			a = xx[i]
			b = yy[-i]
			if len(a) == 0 or len(b) == 0:
				continue
			indb = len(b) - 1
			for j in range(len(a)):
				while a[j] + b[indb] < 0 and indb >= 0:
					indb -= 1
				if indb == -1:
					break
				tot += indb + 1
		#print(x, y, xx, yy)
		return tot + solve(x) + solve(y)


t, = I()
for _ in range(t):
	n, = I()
	s = input()
	print(solve(s))