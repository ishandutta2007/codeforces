n,k=map(int,input().split())
a=list(map(int,input().split()))
a=enumerate(a)
a=[(x[1],x[0]) for x in a]
a.sort()
for i in range(n-k):
    if a[i][0]==a[i+k][0]:
        print('NO')
        exit()
a=enumerate(a)
a=[(x[1][1],x[0]%k+1) for x in a]
a.sort()
a=[x[1] for x in a]
print('YES')
print(*a)