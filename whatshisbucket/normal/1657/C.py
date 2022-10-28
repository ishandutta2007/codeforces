# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())
 
import sys
I=lambda:[*map(int,sys.stdin.readline().split())]
 
t, = I()
for _ in range(t):
	n, = I()
	s = input()
	curr = 0
	ops = 0
	while True:
		diff = 0
		bad = False
		left = None
		ccurr = curr
		found = False
		while ccurr < n:
			if found:
				break
			if left is None:
				if s[ccurr] == '(':
					left = True
					diff += 1
				else:
					left = False
					diff -= 1
					bad = True
			else:
				if s[ccurr] == '(':
					diff += 1
					if left:
						found = True
				else:
					diff -= 1
					if diff == 0 or not left:
						found = True
			ccurr += 1
		if found:
			ops += 1
			curr = ccurr
			#print(curr)
		else:
			break
	print(ops, n - curr)