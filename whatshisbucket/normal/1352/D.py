# import io,os
# read = io.BytesIO(os.read(0, os.fstat(0).st_size))
# I = lambda:map(int, read.readline().split())

import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	turns = 0
	alice = 0
	bob = 0
	big = 0
	acurr = 0
	bcurr = n
	thisturn = 0
	while acurr < bcurr:
		if turns % 2 == 0:
			if thisturn <= big:
				alice += a[acurr]
				thisturn += a[acurr]
				acurr += 1
			else:
				turns += 1
				big = thisturn
				thisturn = 0
		else:
			if thisturn <= big:
				bcurr -= 1
				bob += a[bcurr]
				thisturn  += a[bcurr]
			else:
				turns += 1
				big = thisturn
				thisturn = 0
	print(turns + 1, alice, bob)