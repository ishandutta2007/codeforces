x,d=map(int,input().split())
c=1
r="\n"
e=29
b=2**e-1
while x:
 while x<b:e-=1;b>>=1
 r+=f"{c*d} "*e;c+=e;x-=b
print(c-1,r)