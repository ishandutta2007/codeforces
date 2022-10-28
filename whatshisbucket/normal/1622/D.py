M,F,f,r=998244353,[1],[1],range
for i in r(1,5001):F+=[F[-1]*i];f+=[f[-1]*pow(i,-1,M)%M]
n,k=map(int,input().split());b,s=lambda n,m:F[n]*f[m]*f[n-m],input();o,T=[i for i in r(n)if s[i]>'0'],1;l=len(o);o+=[n]*k+[-1]
for i in r(l):e=o[i+k]-1;x=min(k,l-i);T+=b(e-o[i-1],x)-b(e-o[i],x-1)
print([T%M,1][l<k])