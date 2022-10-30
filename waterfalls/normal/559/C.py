MOD = 10**9+7
fact = [1]*200013
for i in range(1,200013):
    fact[i] = (fact[i-1]*i)%MOD
inv = [1]*200013
for i in range(2,200013):
    inv[i] = (-(MOD//i)*inv[MOD%i])%MOD
for i in range(2,200013):
    inv[i] = (inv[i]*inv[i-1])%MOD
def combo(a,b):
    return (fact[a]*inv[b]*inv[a-b])%MOD
h,w,n = map(int,input().split())
pt = []
for i in range(n):
    r,c = map(int,input().split())
    r,c = r-1,c-1
    pt.append(r*w+c)
pt.append(h*w-1)
pt.sort()
dp = []
for i in range(n+1):
    r,c = pt[i]//w,pt[i]%w
    dp.append(combo(r+c,r))
    for j in range(i):
        r1,c1 = pt[j]//w,pt[j]%w
        if r1<=r and c1<=c:
            dp[i]-=dp[j]*combo(r+c-r1-c1,r-r1)
    dp[i]%=MOD
print(dp[n])