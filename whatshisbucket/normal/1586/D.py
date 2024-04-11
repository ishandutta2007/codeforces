import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

n = int(inpu())
ones = '? ' + "1 "*(n-1)
relative = [0]*n
i = 2
while i <= n:
	prin(ones)
	prin(str(i)+'\n')
	sys.stdout.flush()
	k = int(inpu())
	if k == 0:
		break
	relative[k-1] = i-1
	i += 1
i = 2
while i <= n:
	prin('? ')
	for j in range(n-1):
		prin(str(i) + ' ')
	prin('1\n')
	sys.stdout.flush()
	k = int(inpu())
	if k == 0:
		break
	relative[k-1] = -i+1
	i += 1
sml = min(relative)
for i in range(n):
	relative[i] = str(relative[i] - sml + 1)
prin('! ' + ' '.join(relative))