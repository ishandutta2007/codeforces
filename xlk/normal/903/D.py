from collections import *
n=input()
a=map(int,raw_input().split())
s=0
c=Counter()
for i in range(n):
	s+=(2*i-n+1)*a[i]-c[a[i]-1]+c[a[i]+1]
	c[a[i]]+=1
print s