n,m,k=[int(k) for k in raw_input().split(" ")]

def bezout(a,b) :              # retourne (g,u,v) tel que g = a*u + b*v et g = pgcd(a,b)
    if b == 0 : return (a,1,0)
    q = a // b 
    r = a % b
    (g,u1,v1) = bezout(b,r)    
    return (g,v1,u1-q*v1)      # joli algo :-)


p=bezout(n,k)[0]

n2=n/p
k2=k/p
p=bezout(m,k2)[0]
m2=m/p
k2/=p

if k2>2:
    print "NO"
if k2==1:
    if n2<=n/2:
        n2*=2
        k2*=2
    else:
        m2*=2
        k2*=2
if k2==2:
    print "YES"
    print "0 0"
    print "{} 0".format(n2)
    print "0 {}".format(m2)