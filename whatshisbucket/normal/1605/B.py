import sys
import time
inpu = sys.stdin.readline
prin = sys.stdout.write

t = int(inpu())
for _ in range(t):
	n = int(inpu())
	s = inpu()
	z = s.count('0')
	inds = []
	for i in range(n):
		if i < z and s[i] == '1':
			inds.append(str(i + 1))
		elif i >= z and s[i] == '0':
			inds.append(str(i + 1))
	if len(inds) == 0:
		print(0)
	else:
		print(1)
		print(len(inds), ' '.join(inds))