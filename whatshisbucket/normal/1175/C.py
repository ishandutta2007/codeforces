t=int(input())
out=[0]*t
for u in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    best=float("inf")
    coord=None
    for i in range(n-k):
        if a[i+k]-a[i]<best:
            coord=(a[i+k]+a[i])//2
            best=a[i+k]-a[i]
    out[u]=coord
print(*out,sep='\n')