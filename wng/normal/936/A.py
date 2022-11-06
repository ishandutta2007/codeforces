k,d,t=[int(k) for k in raw_input().split(" ")]

#def tps(tt,,k=k,d=d,t=t):
force=[2,1]
tpos=[k,(d-k)%d]
res=0
t*=2
ffmax=sum([force[i]*tpos[i] for i in range(2)])
res+=sum(tpos)*(t/ffmax)
t=t%ffmax
#print res,t
i=0
while t>0:
    fmax=force[i]*tpos[i]
    if t<=fmax:
        res+=(t/float(fmax))*tpos[i]
        t=0
    else:
        t-=fmax
        res+=tpos[i]
        i=1-i

print res