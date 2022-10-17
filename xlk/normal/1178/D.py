n = input()
m = n
def isPrime(x):
	for i in xrange(2, x):
		if x % i == 0:
			return False
		if i * i > x:
			break
	return True

while not isPrime(m):
	m += 1

print m
for i in range(n):
	print (i + 1), (i + 1) % n + 1
for i in range(m - n):
	print (i + 1), i + n / 2 + 1