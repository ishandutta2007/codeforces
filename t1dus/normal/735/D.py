# from math import ceil,floor
# def matches(n,left):
# 	pass
# n = int(input())
# if n%2 == 0:
# 	print(1+matches(n//2,0))
# else:
# 	print(1+matches(ceil(n/2),1))	
# print(ans)	
primes = [2,3]
x = 3
while x < 200000:
	x += 2
	for i in primes:
		if i*i > x:
			primes.append(x)
			break
		elif x%i == 0:
			break
def is_prime(n):
	for i in primes:
		if i*i > n:
			return True
		if n%i == 0:
			return False
d = {}
def result(n):
	if is_prime(n):
		return 1
	else:
		try:
			return d[n]
		except:	
			a = []
			count = 0
			for i in range(n-2,0,-1):
				if is_prime(i):
					count += 1
					a.append(i)
				if count > 100:
					break
			a = [result(n-i) for i in a]
			ans = 1+min(a)
			d[n] = ans
			return ans							
n = int(input())
print(result(n))