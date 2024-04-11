import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	s = inpu().strip()
	if len(s) > 1:
		prin(s[:-1] + s[0])
	else:
		prin(s)
	prin('\n')