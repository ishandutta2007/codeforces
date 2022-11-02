R=lambda:map(int,input().split())
n,m=R()
a=set(range(1,n+1))
for i in range(m):a=a-set(R())
a=list(a)[0]
print(n-1)
for i in range(1,n+1):
    if i!=a:print(a,i)