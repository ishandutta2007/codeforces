from math import *
B=1000000007
R=lambda:map(int,raw_input().split())
C=lambda n,k:factorial(n)/(factorial(k)*factorial(n-k))
n,m=R()
a=sorted(R())
res,p=1,[]
for i in range(1,m):
    if (a[i]-a[i-1]-2>=0):
        p+=[a[i]-a[i-1]-1]
        res=(res*(2**(a[i]-a[i-1]-2)))%B
if (a[0]!=1):p+=[a[0]-1]
if (a[m-1]!=n):p+=[n-a[m-1]]
t=sum(p)
for i in range(len(p)):
    res*=C(t,p[i])
    res%=B
    t-=p[i]
print res