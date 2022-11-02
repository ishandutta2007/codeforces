R=lambda:map(int,raw_input().split())
n,m,k=R()
s=R()
u=[R() for _ in range(m)]
a,c,q=[0]*(m+1),0,[0]*(n+1)
for _ in range(k):
    x,y=R()
    a[x-1]+=1
    a[y]-=1
for i in range(m):
    c+=a[i]
    d=u[i][2]*c
    q[u[i][0]-1]+=d
    q[u[i][1]]-=d
for i in range(n):
    q[i]+=[0,q[i-1]][i>0]
    s[i]+=q[i]
print " ".join(map(str,s))