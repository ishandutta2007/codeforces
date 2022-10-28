import sys
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	s = []
	for i in range(n):
		s.append(str(100000 + i))
	print(' '.join(s))