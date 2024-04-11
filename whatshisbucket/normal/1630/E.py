import math
import sys
r=range
m=lambda x:pow(x,M-2,M)
M=998244353
f=[1]
F=[1]*10**6
for i in r(1,1000001):f.append(f[-1]*i%M)
F.append(m(f[-1]))
for i in r(10**6,1,-1):F[i-1]=F[i]*(i)%M
I=sys.stdin.readline
for _ in[0]*int(I()):
	n=int(I());a=[*map(int,I().split())];C=[0]*n;P,c=0,0;A={}
	for g in a:C[g-1]+=1
	C=[g for g in C if g>0]
	x=C[0]
	for g in C:x=math.gcd(x,g)
	if x==n:print(1);continue
	for i in r(1,n):
		if x%i<1:A[i]=0
	for i in r(1,n):
		if x%i<1:
			X=n//i;p=f[X];s=0;e=i-A[i]
			for g in C:y=g//i;s+=y*(y-1);p=p*F[y]%M
			P+=p*e;c+=e*((X)*(X-1)-s)*i*m(X-1)*p%M
			for g in A:
				if g%i<1:A[g]+=e
	print(c*m(P)%M)