n,r=map(int,input().split())
location=list(map(int,input().split()))
heaterlist=[]
for i in range(len(location)):
    if location[i]==1:
        heaterlist.append(i)
heaterlist.append(10000000)
don=0
if heaterlist[0]>=r or heaterlist[-2]<n-r:
    print(-1)
    don=1
for i in range(len(heaterlist)-2):
    if heaterlist[i+1]-heaterlist[i]>2*r-1 and don==0:
        print(-1)
        don=1
unheated=0
usedheaters=[]
if don==0:
    while unheated<n:
        i=0
        while heaterlist[i]<unheated+r:
            good=heaterlist[i]
            i+=1
        usedheaters.append(good)
        unheated=usedheaters[-1]+r
    print(len(usedheaters))