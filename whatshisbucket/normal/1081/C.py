import math
n,m,k=map(int,input().split())
out=1
for i in range(k):
    out*=(m-1)
    out%=998244353
out*=m
out%=998244353
out*=(math.factorial(n-1)//math.factorial(k)//math.factorial(n-1-k))
out%=998244353
print(out)