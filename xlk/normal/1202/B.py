from collections import*
s=input()
c=Counter((ord(y)-ord(x))%10for x,y in zip(s,s[1:]))
for i in range(100):
	a = [-1] * 10
	for j in range(1, 11):
		for k in range(j+1):
			x = ((j - k) * (i//10) + k * (i%10)) % 10
			if a[x] == -1:
				a[x] = j-1
	z = 0
	for x in c:
		if a[x] == -1:
			z = -1
			break
		else:
			z += a[x] * c[x]
	print(z)