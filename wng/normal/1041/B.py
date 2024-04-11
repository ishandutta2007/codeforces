#[int(k) for k in raw_input().split(" ")]

def bezout(a,b) :              # retourne (g,u,v) tel que g = a*u + b*v et g = pgcd(a,b)
    if b == 0 : return (a,1,0)
    q = a // b 
    r = a % b
    (g,u1,v1) = bezout(b,r)    
    return (g,v1,u1-q*v1)      # joli algo :-)


a,b,x,y=[int(k) for k in raw_input().split(" ")]


pgcd=bezout(x,y)[0]

x/=pgcd
y/=pgcd

print min(a/x,b/y)