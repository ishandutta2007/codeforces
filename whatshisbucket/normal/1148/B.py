n,m,ta,tb,k=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
land=a[0]+ta
ind=0
while b[ind]<land and ind<m-1:
    ind+=1
if ind+k>=m:
    print(-1)
elif k>=n:
    print(-1)
elif a[k]+ta>b[-1]:
    print(-1)
else:
    froma=k
    best=0
    land=a[k]+ta
    while b[ind]<land:
        ind+=1
    for i in range(k+1):
        best=max(best,b[ind+k-froma]+tb)
        froma-=1
        land=a[froma]+ta
        while b[ind-1]>=land and ind>0:
            ind-=1
    print(best)