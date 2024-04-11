M,n,a = 998244353,int(input()),sorted(list(map(int, input().split())))
s,t = (sum(a[n:])-sum(a[:n]))%M,1
for i in range(1,n+1):
    s = (s*(2*n-i+1))%M
    t = (t*i)%M
print((pow(t,M-2,M)*s)%M)