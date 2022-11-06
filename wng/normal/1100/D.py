from sys import stdout,exit

size=1000
ps=size/3
acs=size-1
a=[int(k)-1 for k in raw_input().split(" ")]
b=[None]*(2*ps)
dt=set()

for i in range(2*ps):
    b[i]=[int(kk)-1 for kk in raw_input().split(" ")]
    dt.add(tuple(b[i]))
    

def towards(fr,to):
        diff=[to[k]-fr[k] for k in range(2)]
        xp=[k/abs(k) if k else 0 for k in diff]
        if len([k for k in xp if k]):
            return [fr[k]+xp[k] for k in range(2)]
        else:
            return None

#Go to 500,500
target=(size/2-1,size/2-1)
z=towards(a,target)
while z is not None:
    if tuple(z) in dt:
        z[1]=a[1]
    print " ".join([str(k+1) for k in z])
    stdout.flush()
    k,x,y=[int(kk)-1 for kk in raw_input().split(" ")]
    if k<=-1:
        exit(0)
    dt.discard(tuple(b[k]))
    dt.add((x,y))
    b[k]=[x,y]
    a=z
    z=towards(a,target)

def quadrant(p):
    return (1 if p[0]<size/2 else 0)+(2 if p[1]<size/2 else 0)

qs=[0]*4
for i in dt:
    q=quadrant(i)
    for j in range(4):
        if j!=(q^3):
            qs[j]+=1

ts=[(acs-1,acs-1),(0,acs-1),(acs-1,0),(0,0)]
target=None
for i in range(4):
    if qs[i]>=size/2-1:
        target=ts[i]

z=towards(a,target)
nbm=0
while z is not None:
    if tuple(z) in dt:
        z[1]=a[1]
    print " ".join([str(k+1) for k in z])
    stdout.flush()
    k,x,y=[int(kk)-1 for kk in raw_input().split(" ")]
    if k<=-1:
        exit(0)
    dt.discard(tuple(b[k]))
    dt.add((x,y))
    b[k]=[x,y]
    a=z
    nbm+=1
    z=towards(a,target)

print "_".join([str(k) for k in qs+list(target)+[nbm]])