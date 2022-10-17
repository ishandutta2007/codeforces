n, p, l, r = map(int, raw_input().split())

if l == 1 and r == n:
	print 0
elif l == 1 and r != n:
	print abs(p - r) + 1
elif l != 1 and r == n:
	print abs(p - l) + 1
elif l != 1 and r != n:
	print min(abs(p - r), abs(p - l)) + abs(l - r) + 2