n,k,x = map(int,input().split())
a = list(map(int,input().split()))
ans = 0
for i in range(n-k): ans += a[i]
ans += k*x
print(ans)