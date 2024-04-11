import math
m,a,b=map(int,input().split())
g=math.gcd(a,b)
a1=a//g
b1=b//g
alls=g*(a1+b1-1)
dists=[0]+[-1]*(a1+b1-1)
dist=0
far=0
while dist!=b1:
    if dist<b1:
        dist+=a1
        far=max(dist,far)
    else:
        dist-=b1
    if dists[dist]==-1:
        dists[dist]=far
tot=0
for i in range(a1+b1):
    if i*g<=m and dists[i]*g<=m:
        tot+=(m+1-dists[i]*g)
if alls<m:
    mod=m%g
    times=m//g
    diff=times-a1-b1
    tot1=g*(diff*(diff+1)//2)+(mod+1)*(diff+1)
    tot+=tot1
print(tot)