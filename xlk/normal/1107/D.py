import sys
from math import gcd
z = n = int(input())
a = [bin((1 << n) | int(input(), 16))[3:] for i in range(n)]
i = 0
while i < n:
	j = i + 1
	while j < n and a[i] == a[j]:
		j += 1
	z = gcd(z, j - i)
	k = 0
	while k < n:
		l = k + 1
		while l < n and a[i][k] == a[i][l]:
			l += 1
		z = gcd(z, l - k)
		k = l
	i = j
print(z)