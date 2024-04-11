n=int(input())
sumi=0
prod=1
for i in range(n-1):
    prod*=(n-i)
    prod%=998244353
    sumi-=prod
sumi+=n*prod
print(sumi%998244353)