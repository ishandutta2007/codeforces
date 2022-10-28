def path(x1,y1,x2,y2,hor):
    out=[]
    if hor:
        for i in range(x2-x1):
            out.append((x1+i,y1))
        if y2>y1:
            for i in range(y2-y1):
                out.append((x2,y1+i))
        else:
            for i in range(y1-y2):
                out.append((x2,y1-i))
    else:
        for i in range(x2-x1):
            out.append((x2-i,y2))
        if y2>y1:
            for i in range(y2-y1):
                out.append((x1,y2-i))
        else:
            for i in range(y1-y2):
                out.append((x1,y2+i))
    return out[1:]
a,b=map(int,input().split())
c,d=map(int,input().split())
e,f=map(int,input().split())
if a>c:
    a,b,c,d=c,d,a,b
if c>e:
    c,d,e,f=e,f,c,d
if a>c:
    a,b,c,d=c,d,a,b
if c==e and abs(f-b)<abs(d-b):
    c,d,e,f=e,f,c,d
g1=path(a,b,c,d,True)
if d>b:
    if f<b:
        g2=path(c,b,e,f,True)
    elif f<d:
        g2=path(c,f,e,f,True)
    else:
        g2=path(c,d,e,f,True)
else:
    if f<d:
        g2=path(c,d,e,f,True)
    elif f<b:
        g2=path(c,f,e,f,True)
    else:
        g2=path(c,b,e,f,True)
print(len(g1)+len(g2)+3)
print(a,b)
print(c,d)
print(e,f)
for x,y in g1:
    print(x,y)
for x,y in g2:
    print(x,y)