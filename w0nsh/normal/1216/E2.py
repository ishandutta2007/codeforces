q = int(input())

def ar(n):
	return n*(n+1)//2

def sm(a, r, n):
	return a*n+(n-1)*(n)//2*r

def cale(n):
	if n == 0:
		return 0
	return cale(n-1) + 9*10**(n-1)*n

def zaj(n):
	poz = 1
	while True:
		left = 1
		right = 9*10**(poz-1)+1
		while left < right:
			mid = (left+right)//2
			cur = cale(poz-1)*mid
			cur += sm(poz, poz, mid)
			# print('mid {} cur {}'.format(mid, cur))
			if cur >= n:
				right = mid
			else:
				left = mid+1
		if left == 9*10**(poz-1)+1:
			left = 9*10**(poz-1)
			n -= cale(poz-1)*left
			n -= sm(poz, poz, left)
			poz += 1
			assert n > 0, 'n == 0'
		else:
			left -= 1
			n -= cale(poz-1)*left
			n -= sm(poz, poz, left)
			ktory = 10**(poz-1)+left
			return (ktory, n)


for asdsjfhajfhsajf in range(q):
	k = int(input())
	_, n = zaj(k)
	poz = 1
	while True:
		left = 1
		right = 9*10**(poz-1)+1
		while left < right:
			mid = (left+right)//2
			cur = poz*mid
			if cur >= n:
				right = mid
			else:
				left = mid+1
		if left == 9*10**(poz-1)+1:
			left -= 1
			n -= poz*left
			poz += 1
			assert n > 0, 'n == 0 down'
		else:
			left -= 1
			# print('{} left'.format(left))
			n -= poz*left
			l = str(10**(poz-1)+left)
			# print(str(n) + ' w ' + l)
			print(l[n-1])
			break