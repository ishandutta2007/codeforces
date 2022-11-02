p,n=map(int,raw_input().split())
a={}
for i in range(n):
	k=input()%p
	if k in a:
		print i+1
		break
	a[k]=1
else:print -1