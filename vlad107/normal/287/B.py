f=lambda k,x:(2*k-x+1)*x/2-x
n,k=map(long,raw_input().split())
if (n<=k):
    print [0,1][n!=1]
    exit(0)
t,n,k=1,n-k,k-1
for i in reversed(range(60)):
    if (2**i<k)&(f(k,2**i)<=n):n,t,k=n-f(k,2**i),t+2**i,k-2**i
print [-1,t+(n>0)][(n<k)&(n>=0)]