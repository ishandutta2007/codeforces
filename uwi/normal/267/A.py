import sys

nt = int(sys.stdin.readline())
for t in range(nt):
	(a, b) = [int(x) for x in sys.stdin.readline().split(" ")]
	ct = 0
	while b > 0:
		c = a%b
		ct = ct + a/b
		a = b
		b = c
	print ct