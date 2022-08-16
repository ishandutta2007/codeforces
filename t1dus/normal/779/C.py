n,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = []
for i in range(n):
    c.append([a[i],b[i]])
c.sort(key = lambda x: x[0]-x[1])
ans = 0
for i in range(k):
    ans += c[i][0]
for i in range(k,n):
    ans += min(c[i][0],c[i][1])
print(ans)