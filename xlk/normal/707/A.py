import sys
s = sys.stdin.read()
if s.count('C') + s.count('M') + s.count('Y') > 0:
	print '#Color'
else:
	print '#Black&White'