import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

def is_prime(k):
	if k < 4:
		return True
	for i in range(2, int(k ** 0.5) + 1):
		if k % i == 0:
			return False
	return True

def is_prime_power(k):
	if k < 4:
		return True
	for i in range(2, int(k ** 0.5) + 1):
		if k % i == 0:
			factor = i
			break
	else:
		return True
	while k % factor == 0:
		k //= factor
	if k == 1:
		return True
	return False

t, = I()
for _ in range(t):
	x, d = I()
	power = 0
	while x % d == 0:
		power += 1
		x //= d
	if power == 1:
		print('no')
		continue
	if is_prime(d):
		if is_prime(x):
			print('no')
			continue
		print('yes')
	elif is_prime_power(d):
		if power == 2 and is_prime(x):
			print('no')
		elif power == 3 and is_prime(x) and x ** 2 == d:
			print('no')
		else:
			print('yes')
	else:
		if power == 2 and is_prime(x):
			print('no')
		else:
			print('yes')