r=lambda:map(int,raw_input().split())
n,m=r()
k=input()
a=[r()for i in range(k)]
p=input()
if n>m:
	n,m=m,n
	for i in a:
		i[0],i[1]=i[1],i[0]
c=[0]*m
w=[1]*m
for i in a:
	i[1]-=1
	c[i[1]]+=1
	w[i[1]]*=i[2]
z=1-n
for i in range(m):
	if c[i]==n and w[i]>0:
		print 0
		exit()
	else:
		z+=max(0,n-c[i]-1)
print [pow(2,z,p),0][n+m&1]