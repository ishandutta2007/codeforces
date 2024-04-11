import sys
import math
inpu = sys.stdin.readline
prin = sys.stdout.write

def factors(n):
	out = []
	for i in range(1,int(n**0.5)+1):
		if n%i == 0:
			out.append(i)
			out.append(n//i)
	if out[-1] == out[-2]:
		out.pop(-1)
	return sorted(out)
t = int(inpu())
for _ in range(t):
	n = int(inpu())
	a = list(map(int,inpu().split()))
	count = [0]*30
	for guy in a:
		b = bin(guy)[2:]
		for i in range(len(b)):
			if b[i] == "1":
				count[len(b)-1-i] += 1

	if count == [0]*30:
		prin(" ".join([str(i+1) for i in range(n)]) + '\n')
	else:
		g = count[0]
		for i in range(1, 30):
			g = math.gcd(g, count[i])
		prin(" ".join([str(guy) for guy in factors(g)]) + '\n')