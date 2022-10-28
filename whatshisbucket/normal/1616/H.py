I=lambda:[*map(int,input().split())]
M=998244353
n,X=I()
a=I()
q=lambda x:pow(2,x,M)-1
E=len
B=lambda a,H:[[z for z in a if z>>H&1==d]for d in[0,1]]
def f(a,b,i):
	if i<0 or[]in[a,b]:return q(E(a))*q(E(b))
	w,x=B(a,i);y,z=B(b,i);return(f(x,y,i-1)+q(E(x))+q(E(y))+1)*(f(w,z,i-1)+q(E(w))+q(E(z))+1)-q(E(a))-q(E(b))-1 if X>>i&1 else f(x,z,i-1)+f(w,y,i-1)
def F(a,i):
	if i<0 or[]==a:return q(E(a))
	x,y=B(a,i);return q(E(x))+q(E(y))+f(x,y,i-1)if X>>i&1 else F(x,i-1)+F(y,i-1)
print(F(a,29)%M)