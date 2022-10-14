n,k = map(int,input().split())
dp = [1,2]
for i in range (2,60):
    dp.append(dp[i-1]+dp[i-2])
a = [i+1 for i in range(0,n)]
k -= 1
for i in range(0,n-1):
    if (k >= dp[n-i-2]):
        k -= dp[n-i-2]
        a[i],a[i+1] = a[i+1],a[i]
for i in range (n):
    print(a[i], end = " ")