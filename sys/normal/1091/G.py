from random import *
import math

def gcd(a, b):
	if a == 0:
		return b
	else:
		return gcd(b % a, a)


n = int(input())
val = []
ans = []
for _ in range(50):
	x = randint(1, n - 1)
	print("sqrt %d" % (x * x % n))
	y = int(input())
	if x != y:
		if x > y:
			x, y = y, x
		val.append(y - x), val.append(n // (y - x))
while n != 1:
	p = n
	for i in range(len(val)):
		if gcd(p, val[i]) != 1:
			p = gcd(p, val[i])
	for i in range(len(val)):
		if val[i] % p == 0:
			val[i] = val[i] // p
	while n % p == 0:
		n = n // p
	ans.append(p)
print("!", len(ans), *ans)