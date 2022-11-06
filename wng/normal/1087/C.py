a=[int(k) for k in raw_input().split(" ")]
b=[int(k) for k in raw_input().split(" ")]
c=[int(k) for k in raw_input().split(" ")]


a,b,c=sorted([a,b,c])

def ft(u,v):
    if u>v:
        u,v=v,u
    x,y=u
    x2,y2=v
    res=[(i,y) for i in range(x+1,x2+1)]
    if y2>y:
        res+=[(x2,i) for i in range(y+1,y2+1)]
    else:
        res+=[(x2,i) for i in range(y-1,y2-1,-1)]
    return res

def ft(u,v):
    x,y=u
    x2,y2=v
    res=[(i,y) for i in range(x+1,x2+1)] if x2>=x else [(i,y) for i in range(x-1,x2-1,-1)]
    if y2>y:
        res+=[(x2,i) for i in range(y+1,y2+1)]
    else:
        res+=[(x2,i) for i in range(y-1,y2-1,-1)]
    return res


    
#is b between a and c y wise?
res=None
if (b[1]-a[1])*(c[1]-b[1])>=0:
    #atobtoc
    res=[a]+ft(a,b)+ft(b,c)
else:
    if b[1]>a[1] and b[1]>c[1]:
        ai=[a[0],max(a[1],c[1])]
        res=[a]+ft(a,ai)+ft(ai,c)+ft([b[0],max(a[1],c[1])],b)
        #atochighpuis ptoatoc
    else:
        #atoclowpuisbtoatoc
        ai=[a[0],min(a[1],c[1])]
        res=[a]+ft(a,ai)+ft(ai,c)+ft([b[0],min(a[1],c[1])],b)
print len(res)
print "\n".join([" ".join([str(k) for k in i]) for i in res])