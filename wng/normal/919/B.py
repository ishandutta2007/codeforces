n=[int(k) for k in raw_input().split(" ")][0]
d=[0]*15000000

def sd(i):
    global d
    if not i:
        return 0
    if not d[i]:
        d[i]=i%10+sd(i/10)
    return d[i]

nbk=0
i=1
ks=0
nd=0
r=[]
while nbk<n:
    i+=9
    nd=sd(i)
    if nd==10:
        nbk+=1
        r+=[i]

print r[-1]