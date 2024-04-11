n,m=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
x=int(input())
gooda=[10000000]*n
goodb=[10000000]*m
for i in range(n):
    tots=0
    lent=0
    for j in range(i,n):
        tots+=a[j]
        lent+=1
        gooda[lent-1]=min(gooda[lent-1],tots)
for i in range(m):
    tots=0
    lent=0
    for j in range(i,m):
        tots+=b[j]
        lent+=1
        goodb[lent-1]=min(goodb[lent-1],tots)
best=0
aind=0
bind=m-1
while aind<n and bind>=0:
    if gooda[aind]*goodb[bind]<=x:
        best=max(best,(aind+1)*(bind+1))
        aind+=1
    else:
        bind-=1
print(best)