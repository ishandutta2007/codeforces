import sys
M=10**9+7;f=[1];F=[1];r=range;I=sys.stdin.readline
for i in r(1,1000009):f.append(f[-1]*i%M);F.append(F[-1]*pow(i,M-2,M)%M)
for _ in r(int(I())):n,m,k=map(int,I().split());q=pow(500000004,n-1,M);t=sum(x*f[n]*F[m-x]*F[n+x-m]%M for x in r(m+1));print(t*q*k%M)