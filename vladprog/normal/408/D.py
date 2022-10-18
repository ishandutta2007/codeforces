MOD=int(1e9+7)

n=int(input())
a=list(map(int,input().split()))
dp=[]
for i in range(n):
    res=2
    for j in range(a[i]-1,i):
        res=(res+dp[j])%MOD
    dp+=[res]
print(sum(dp)%MOD)