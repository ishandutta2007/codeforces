n,m=map(int,input().split())
abil=[]
for i in range(m):
    abil.append([])
for i in range(n):
    s,r=map(int,input().split())
    abil[s-1].append(r)
use=[None]*m
for i in range(m):
    abil[i].sort(reverse=True)
    sumi=0
    for j in range(len(abil[i])):
        sumi+=abil[i][j]
        if sumi<=0:
            use[i]=(j,i,sumi-abil[i][j])
            break
        if j==len(abil[i])-1:
            use[i]=(j+1,i,sumi)
    if abil[i]==[]:
        use[i]=(0,i,0)
use.sort()
inuse={i for i in range(m)}
total=0
remove=0
persons=0
best=0
while len(inuse)>0:
    while use[remove][0]<=persons:
        inuse.discard(use[remove][1])
        total-=use[remove][2]
        if inuse==set():
            break
        remove+=1
    for guy in inuse:
        total+=abil[guy][persons]
    best=max(best,total)
    persons+=1
print(best)