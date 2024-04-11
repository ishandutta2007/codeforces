N =int(input())

e =1
B =False
while True:
	a =1
	b =N+1
	if a*(a-3)//2+e*a > N: break
	while b-a > 1:
		c =(b+a)//2
		if e*c+c*(c-3)//2 <= N: a =c
		else: b =c
#	print(a)
	if (a%2 != 0) & (e*a+a*(a-3)//2 == N): 
		B =True
		print(a*e)
	e *=2
if B == False: print(-1)