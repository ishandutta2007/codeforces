n=input()
k=n/2
for i in range(n):
	print '*'*abs(k-i)+'D'*(n-abs(k-i)*2)+'*'*abs(k-i)