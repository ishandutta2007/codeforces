import math
for t in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	z = 0
	for i in a:
		z = math.gcd(z, i - a[0])
	if z == 0:
		z = -1
	print(z)