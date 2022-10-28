import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

def nu2(n):
	i = 0
	while n % 2 == 0:
		i += 1
		n //= 2
	return i

n = int(inpu())
a = list(map(int, inpu().split()))

even = [guy for guy in a if guy % 2 == 0]
two = [nu2(guy) for guy in even]
two.sort()
counts = [0]*two[-1]
for guy in two:
	counts[guy - 1] += 1
#print(counts)
bad = 0
m = 1000000007
for i in range(len(counts)):
	if counts[i] > 0:
		bad += pow(2, sum(counts[i:]) - 1, m)
print((pow(2, n, m)-bad-1)%m)