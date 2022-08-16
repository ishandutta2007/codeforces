n,k = map(int,input().split())
a = list(map(int,input().split()))
ans = -100000000
for i in range(k):
    cnt = 0
    for j in range(n):
        if j%k != i:
            cnt += a[j]
    ans = max(ans,abs(cnt))
print(ans)