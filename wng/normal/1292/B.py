x0,y0,ax,ay,bx,by=[int(k) for k in input().strip().split(" ")]
xs,ys,t=[int(k) for k in input().strip().split(" ")]

cx=bx/(ax-1)
cy=by/(ay-1)

x0p=x0
y0p=y0

xsp=xs
ysp=ys

xip=x0p
yip=y0p
res=0

def md(x,y,xp,yp):
   # print(x,y,xp,yp)
   # print(abs(x-y)+abs(xp-yp))
    return abs(x-xp)+abs(y-yp)

totdto0=0

pvs=[]

for i in range(200):
    tt=t
    maxres=0
    #print(i)
    tt-=md(xsp,ysp,xip,yip)
    if (tt>=0):
        myres=1
        if (tt>=2*totdto0):
            mr=i+1
            ttt=tt-2*totdto0
            oxip=xip
            oyip=yip
            while (ttt>=0):
                nxip=ax*oxip+bx
                nyip=ay*oyip+by
                ttt-=md(nxip,nyip,oxip,oyip)
                if (ttt>=0):
                    mr+=1
                oyip=nyip
                oxip=nxip
            maxres=max(maxres,mr)
        if (tt>=totdto0):
            mr=i+1
            maxres=max(maxres,mr)
        else:
            oxip=xip
            oyip=yip
            ttt=tt
            kk=-1
            mr=1
            while (ttt>=0 and -kk<=len(pvs)):
                nxip=pvs[kk][0]
                nyip=pvs[kk][1]
                ttt-=md(nxip,nyip,oxip,oyip)
                if (ttt>=0):
                    mr+=1
                kk-=1
                oyip=nyip
                oxip=nxip
            maxres=max(maxres,mr)
        mr=1
        ttt=tt
        oxip=xip
        oyip=yip
        while (ttt>=0):
            nxip=ax*oxip+bx
            nyip=ay*oyip+by
            ttt-=md(nxip,nyip,oxip,oyip)
            if (ttt>=0):
                mr+=1
            oyip=nyip
            oxip=nxip
    res=max(res,maxres)
    #print(i,maxres)
    oxip=xip
    oyip=yip
    pvs+=[(oxip,oyip)]
    xip*=ax
    xip+=bx
    yip*=ay
    yip+=by
    totdto0+=md(xip,yip,oxip,oyip)
    if (xip>xsp and yip>ysp and (xip+yip-xsp-ysp)>t):
        break
print(res)