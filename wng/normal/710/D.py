
def bezout(a,b) :              # retourne (g,u,v) tel que g = a*u + b*v et g = pgcd(a,b)
    if b == 0 : return (a,1,0)
    q = a // b 
    r = a % b
    (g,u1,v1) = bezout(b,r)    
    return (g,v1,u1-q*v1)      # joli algo :-)

a1,a2,b1,b2,L,R=[int(k) for k in raw_input().split(" ")]


g,q,r=bezout(a1,b1)

res=0
#ok c donc equivalent a a1,b1,a2-k,b2-k,L-k,R-k  si b1%g=b2%g=k sinon pas de sol
if a2%g==b2%g:
    k=a2%g
    L-=k
    R-=k
    res=1
#ok c donc equivalent a a1/g,b1/g,a2/g,b2/g,(L-k)/g,(R-k)/g
a1/=g
b1/=g
a2/=g
b2/=g
L/=g
R/=g

a2or=a2
b2or=b2
a2p=a2/a1
b2p=b2/b1
a2%=a1
b2%=b1
#note : on a garde le qr tq  qa1+rb1=1
#On veut  xa1-yb1=b2-a2
x=(q*(b2-a2))%b1
y=-(r*(b2-a2))%a1
assert (x*a1-y*b1)%(a1*b1)==(b2-a2)%(a1*b1)
#ok tous les k*a1b1 + (x+kb1)a1 + (y+ka1)*b1
#quel est le min k tel que x+kb1>=0
L=max(L,a2or,b2or)
L2=L+( (x*a1+a2)%(a1*b1) - L%(a1*b1))%(a1*b1)
print  res*max((R-L2)/(a1*b1)+1,0)