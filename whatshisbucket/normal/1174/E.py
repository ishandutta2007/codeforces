p=10**9+7
import math
def r(l):
    x=1
    for m in l:
        x=x*m%p
    return x
n=int(input())
a,k,x,t=[],int(math.log2(n)),n,0
while x>0:
    a.append(x-x//2)
    x//=2
b=[n//(3*2**i)-n//(6*2**i) for i in range(k+1)]
d=[n//2**i-n//(3*2**i) for i in range(k+1)]
y=r(i for i in range(2,n+1))
s=k if n<3*2**(k-1) else 0
for j in range(s,k+1):
    e=[a[i] for i in range(j)]+[d[j]]+[b[i] for i in range(j,k)]
    x=y*r(e)%p
    f=r(sum(e[:i+1]) for i in range(k+1))
    while f>1:
        x*=p//f+1
        f=f*(p//f+1)%p
    t+=x%p
print(t%p)