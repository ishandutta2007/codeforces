n, k = map(int, input().split())

mod = 1000003

if n < 70 and 2**n < k:
	print('1 1\n')
	exit(0)

def modpow(a, e):
	ret = 1
	while e > 0:
		if e%2 == 1:
			ret = (ret*a)%mod
		a = (a*a)%mod
		e = e//2
	return ret

def pw(a, e):
	ret = 1
	while e > 0:
		if e%2 == 1:
			ret *= a
		a *= a
		e = e//2
	return ret

par = n
for i in range(1, 100):
	par += ((k-1)//pw(2, i))

mul = 1
cur = modpow(2, n)
for i in range(k):
	mul = (cur*mul)%mod
	cur -= 1
	if mul == 0:
		break
if mul != 0:
	mul = (mul*modpow(modpow(2, par), mod-2))%mod

up = (modpow(2, n*k-par)-mul)%mod
if up < 0:
	up += mod

print(up, end=' ')
print(modpow(2, n*k-par))