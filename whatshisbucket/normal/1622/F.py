import random
import time
n = int(input())
n += 1
era = [0] * n
primes = []
for i in range(2, n):
	if era[i] == 0:
		primes.append(i)
		k = i
		while k < n:
			if era[k] == 0:
				era[k] = i
			k += i

hashes = {}
prime = {}
for guy in primes:
	r = random.randrange(0, 1 << 48)
	while r in prime:
		r = random.randrange(0, 1 << 48)
	hashes[guy] = r
	prime[r] = guy

hashall = [0, 0]
for i in range(2, n):
	xor = 0
	k = i
	while k > 1:
		p = era[k]
		i = 0
		while p == era[k]:
			k //= p
			i += 1
		if i % 2 == 1:
			xor ^= hashes[p]
	hashall.append(xor)
hashfac = [0, 0]
for i in range(2, n):
	hashfac.append(hashfac[-1] ^ hashall[i])

facmap = {}
for i in range(1, n):
	facmap[hashfac[i]] = i

total = 0
for i in range(1, n):
	total ^= hashfac[i]

if total == 0:
	print(n - 1)
	print(*[i for i in range(1, n)])
elif total in facmap:
	k = facmap[total]
	size = n - 2
	print(size)
	print(*[i for i in range(1, n) if i != k])
else:
	for i in range(1, n):
		x = total ^ hashfac[i]
		if x in facmap:
			j = facmap[x]
			print(n - 3)
			print(*[l for l in range(1, n) if l != i and l != j])
			break
	else:
		print(n - 4)
		print(*[i for i in range(1, n) if i != 2 and i != n - 1 and i != (n - 2)//2])