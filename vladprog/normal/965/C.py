n,k,m,d=map(int,input().split())
ans=0
for t in range(1,d+1):
    x=n//(k*t-k+1)
    if x<=m:
        ans=max(ans,t*x)
x=m
t=(n//x+k-1)//k
if t<=d:
    ans=max(ans,t*x)
print(ans)