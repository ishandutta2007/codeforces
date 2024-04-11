r=lambda:map(int,raw_input().split())
n,m,k,t=r()
k=[r()for i in range(k)]
for i in range(t):
	a=r()
	if a in k:
		print"Waste"
	else:
		print["Grapes","Carrots","Kiwis"][(a[0]*m-m+a[1]-sum(map(lambda i:i<a,k)))%3]