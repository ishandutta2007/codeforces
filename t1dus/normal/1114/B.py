n,m,k = map(int,input().split())
a = list(map(int,input().split()))
b = [[a[i],i] for i in range(n)]
b.sort(reverse = True)
c = []
ans = 0
for i in range(m*k):
    ans += b[i][0]
    c.append(b[i][1])
c.sort()
print(ans)
for i in range(k-1):
    print(c[(i+1)*m-1]+1,end=' ')
print()