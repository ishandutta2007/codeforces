a,b,c=map(int,input().split())
x1,y1,x2,y2=map(int,input().split())
if a==0 or b==0 or x1==x2 or y1==y2:
    print(abs(x1-x2)+abs(y1-y2))
else:
    u=(-c-b*max(y1,y2))/a
    d=(-c-b*min(y1,y2))/a
    l=(-c-a*min(x1,x2))/b
    r=(-c-a*max(x1,x2))/b
    up=True if (y2-y1)/(x2-x1)>0 else False
    uin=(u<=x1)^(u<=x2) or (u>=x1)^(u>=x2)
    din=(d<=x1)^(d<=x2) or (d>=x1)^(d>=x2)
    rin=(r<=y1)^(r<=y2) or (r>=y1)^(r>=y2)
    lin=(l<=y1)^(l<=y2) or (l>=y1)^(l>=y2)
    if uin and din:
        if up^(a*b>0):
            print(abs(x1-x2)-abs(u-d)+((u-d)**2+(y1-y2)**2)**0.5)
        else:
            print(abs(x1-x2)+abs(y1-y2))
    elif rin and lin:
        if up^(a*b>0):
            print(abs(y1-y2)-abs(r-l)+((r-l)**2+(x1-x2)**2)**0.5)
        else:
            print(abs(x1-x2)+abs(y1-y2))
    elif lin and uin and up:
        if x1>x2:
            x1,x2,y1,y2=x2,x1,y2,y1
        print(l-y1+x2-u+((y2-l)**2+(u-x1)**2)**0.5)
    elif rin and din and up:
        if x1>x2:
            x1,x2,y1,y2=x2,x1,y2,y1
        print(y2-r+d-x1+((x2-d)**2+(r-y1)**2)**0.5)
    elif lin and din and not up:
        if x1>x2:
            x1,x2,y1,y2=x2,x1,y2,y1
        print(y1-l+x2-d+((d-x1)**2+(l-y2)**2)**0.5)
    elif rin and uin and not up:
        if x1>x2:
            x1,x2,y1,y2=x2,x1,y2,y1
        print(u-x1+r-y2+((y1-r)**2+(x2-u)**2)**0.5)
    else:
        print(abs(x1-x2)+abs(y1-y2))