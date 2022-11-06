
def bezout(a,b) :              # retourne (g,u,v) tel que g = a*u + b*v et g = pgcd(a,b)
    if b == 0 : return (a,1,0)
    q = a // b 
    r = a % b
    (g,u1,v1) = bezout(b,r)    
    return (g,v1,u1-q*v1)      # joli algo :-)
    
n,m,x,y,vx,vy=[int(k) for k in raw_input().split(" ")]

if vx==0:
    if not x:
        if y>0:
            print 0,m
        else:
            print 0,0
    elif x==n:
        if vy>0:
            print n,m
        else:
            print n,0
    else:        
        print -1
        
if vy==0:
    if not y:
        if x>0:
            print n,0
        else:
            print 0,0
    elif y==m:
        if vx>0:
            print n,m
        else:
            print 0,m
    else:        
        print -1
            
if vy*vx:
    mcx=(-x*vx)%n
    mcy=(-y*vy)%m
    g,u,v=bezout(n,m)
    ppcm=n*m/g
    if mcx%g or mcy%g:
        if mcx%g!=mcy%g:
            print -1
        else:   
            ta=mcx%g
            x+=vx*ta
            y+=vy*ta
            mcx=(-x*vx)%n
            mcy=(-y*vy)%m
            minsol=(-(-mcx/g)*v*m-(-mcy/g)*u*n)%ppcm
            p1=n*(((minsol*vx+x)/n)%2)
            p2=m*(((minsol*vy+y)/m)%2)
            print p1,p2
    else:
        minsol=(-(-mcx/g)*v*m-(-mcy/g)*u*n)%ppcm
        p1=n*(((minsol*vx+x)/n)%2)
        p2=m*(((minsol*vy+y)/m)%2)
        print p1,p2