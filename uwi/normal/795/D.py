n,l,r = map(int, raw_input().strip().split())
a = map(int, raw_input().split())
b = map(int, raw_input().split())
l -= 1
r -= 1
import sys
for i in xrange(n):
	if l <= i <= r: continue
	if a[i] != b[i]:
		print "LIE"
		sys.exit(0)
a.sort()
b.sort()
if a == b:
	print "TRUTH"
else:
	print "LIE"