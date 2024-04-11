from math import gcd

def getprime(x):
	for i in range(2, x):
		if x % i == 0:
			return i
	return -1

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

t = int(input())
for _ in range(t):
	n = int(input())
	a = [int(x) for x in input().split()]
	used = [False for i in range(11)]
	clr = []
	for i in range(n):
		x = primes.index(getprime(a[i]))
		used[x] = True
		clr.append(x)
	cnt = 0
	num = []
	for i in range(11):
		num.append(cnt)
		if used[i]:
			cnt += 1
	print(cnt)
	for i in range(n):
		x = primes.index(getprime(a[i]))
		print(num[x] + 1, end = " ")
	print()