n,k=[int(kk) for kk in input().strip().split(" ")]
h=[int(kk) for kk in input().strip().split(" ")]

fact=[1]*(n+1)
mod=998244353
for i in range(1,n+1):
    fact[i]=(fact[i-1]*i)%mod

def inv(x):
    return pow(x,mod-2,mod)

def C(n,k):
    return (fact[n]*inv(fact[k])*inv(fact[n-k]))%mod

ng=0

for i in range(n):
    if (h[i]==h[i-1]):
        ng+=1

np=n-ng

totposs=pow(k,np)

possegales=[C(np,kk)*C(np-kk,kk) * pow(k-2,np-2*kk,mod) for kk in range(np//2 +1)]

res=(totposs-sum(possegales)%mod + mod) % mod *inv(2) * pow(k,ng,mod)
res%=mod
print(res)