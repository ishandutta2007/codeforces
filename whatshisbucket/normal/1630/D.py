import sys
I = lambda: [*map(int, sys.stdin.readline().split())]
 
def consec(a):
	tot = 0
	big = float('inf')
	neg = 0
	for guy in a:
		tot += abs(guy)
		if abs(guy) < big:
			big = abs(guy)
		if guy < 0:
			neg += 1
	if neg % 2 == 0:
		return (tot, tot - 2 * big)
	return (tot - 2 * big, tot)
 
import math

def main():
	n, m = I()
	a = I()
	b = I()
	g = b[0]
	for i in range(1, m):
		g = math.gcd(g, b[i])
 
	if g == 1:
		print(sum(abs(guy) for guy in a))
		return
	
	tot = 0
	tot1 = 0
	for i in range(g):
		guy = []
		j = i
		while j < n:
			guy.append(a[j])
			j += g
		x, y = consec(guy)
		tot += x
		tot1 += y
 
	print(max(tot, tot1))

t, = I()
for _ in range(t):
	main()