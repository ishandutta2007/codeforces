def list_input():
    return list(map(int,input().split()))
def map_input():
    return map(int,input().split())
def map_string():
    return input().split()
    
n,p,q,r = map_input()
a = [p,q,r]
b = list_input()
ans = 0
INF = -100000000000000000000000
dp = [INF]*(n+5)
dp2 = [INF]*(n+5)
dp3 = [INF]*(n+5)
for i in range(n): dp[i] = p*b[i]
for i in range(1,n): dp[i] = max(dp[i],dp[i-1])
for i in range(n): dp2[i] = q*b[i]+dp[i]
for i in range(1,n): dp2[i] = max(dp2[i],dp2[i-1])
for i in range(n): dp3[i] = r*b[i]+dp2[i]
for i in range(1,n): dp3[i] = max(dp3[i],dp3[i-1])
print(dp3[n-1])