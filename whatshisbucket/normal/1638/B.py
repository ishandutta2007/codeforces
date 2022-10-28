import sys
I = lambda:[*map(int, sys.stdin.readline().split())]

t, = I()
for _ in range(t):
	n, = I()
	a = I()
	bigeven = -2
	bigodd = -1
	bad = False
	for i in range(n):
		if a[i] % 2 == 0:
			if a[i] < bigeven:
				bad = True
			else:
				bigeven = a[i]
		else:
			if a[i] < bigodd:
				bad = True
			else:
				bigodd = a[i]
	if bad:
		print("No")
	else:
		print("Yes")