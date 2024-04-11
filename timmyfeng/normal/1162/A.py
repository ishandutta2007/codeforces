n,h,m=map(int,raw_input().split())
 
a=[h]*n
for i in range(m):
	l,r,x=map(int,raw_input().split())
	for j in range(l-1,r):
		a[j]=min(a[j],x)
 
ans=0
for i in a:
	ans+=i*i
 
print(ans)