k2,k3,k5,k6=map(int,input().split())
cnt=min(k2,k5,k6)
ans=cnt*256
k2-=cnt
ans+=32*min(k2,k3)
print(ans)