I=lambda:[*map(int,input().split())]
def F(g,i):s=g//i;b=g%i;return b*(s+1)**2+(i-b)*s**2
def f(g,c):
	if c>g**2//2:return 0,g**2
	s=0;b=g
	while b-s>1:
		m=(b+s)//2
		if F(g,m)-F(g,m+1)>=c:s=m
		else:b=m
	return s,F(g,b)
n,=I()
a=[0]+I()
m,=I()
G=[a[i+1]-a[i]for i in range(n)]
s=2
b=1<<59
while b-s>1:
	C=0;M=(b+s)//2
	for g in G:a,c=f(g,M);C+=c
	if C>m:b=M
	else:s=M
A=C=0
for g in G:a,c=f(g,b);A+=a;C+=c
print(A+max(0,(C-m-1)//s+1))