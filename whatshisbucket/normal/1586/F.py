import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write
def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return digits[::-1]
n,k = map(int,inpu().split())
digits = math.ceil(math.log(n)/math.log(k))
prin(str(digits))
prin('\n')
for i in range(n):
	j = i+1
	diff = 1
	while j < n:
		if i//(k**diff) != j//(k**diff):
			diff += 1
			continue
		prin(str(diff))
		prin(' ')
		j += 1