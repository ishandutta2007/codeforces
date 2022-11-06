nbl=raw_input()
g1=[int(k) for k in raw_input().split(" ")]
g2=[int(k) for k in raw_input().split(" ")]
d1=dict(zip(range(1,6),[0]*5))
d2=dict(zip(range(1,6),[0]*5))
for k in g1:
    d1[k]+=1
for k in g2:
    d2[k]+=1
nbs=0
res=0
for k in range(1,6):
    dk=d1[k]-d2[k]
    if dk%2!=0:
        res=-1
    nbs+=abs(dk/2)
print nbs/2 if res==0 else res