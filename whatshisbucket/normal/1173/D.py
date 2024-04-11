n=int(input())
d=[0]*2*n
for i in range(n-1):
 u,v=map(int,input().split())
 d[u]+=1
 d[v]+=1
 n=n*d[u]*d[v]%998244353
print(n)