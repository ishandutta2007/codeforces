n,k=map(int,input().split())
a=list(map(int,input().split()))
elems=[(a[i],i) for i in range(n)]
ans=[0]*n
elems.sort()
for i in range(n):
    ans[elems[i][1]]=str(i%k+1)
curr=0
elem=-1
long=0
for guy in elems:
    if guy[0]!=elem:
        long=max(long,curr)
        curr=1
        elem=guy[0]
    else:
        curr+=1
long=max(long,curr)
if long>k:
    print("NO")
else:
    print("YES")
    print(" ".join(ans))