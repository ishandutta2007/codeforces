n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]


def pgcd(a,b) :              # retourne g = pgcd(a,b)
    if b == 0 : return a#(a,1,0)
    #q = a // b 
    r = a % b
    g=pgcd(b,r)#(g,u1,v1) = bezout(b,r)    
    return g#(g,v1,u1-q*v1) 


if min(a)==1:
    print n-len([k for k in a if k==1])
else:
    bests=[0]*n
    bb=n+1
    left={}
    for i in range(n):
        left[i]=a[i]
        for k in left.keys():
            bests[k]+=1
            left[k]=pgcd(a[i],left[k])
            if left[k]==1:
                bb=min(bb,bests[k])
                del left[k]
            elif bests[k]>=bb:
                del left[k]
    
    #print bests
    #print left
    if bb==n+1:
        print -1
    else:
        print n-2 + min([bests[k] for k in range(n) if k not in left])