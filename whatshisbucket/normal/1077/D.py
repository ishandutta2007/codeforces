import math
def how(listo,div):
    sumi=0
    for guy in listo:
        if guy[0]<div:
            break
        sumi+=guy[0]//div
    return sumi
n,k=map(int,input().split())
counts=[0]*200000
a=list(map(int,input().split()))
for guy in a:
    counts[guy-1]+=1
stuff=[(counts[i],i+1) for i in range(200000)]
stuff.sort(reverse=True)
maxi=n//k
mini=1
curr=(maxi+mini)//2
while maxi!=mini:
    x=how(stuff,curr)
    if x<k:
        maxi=curr-1
        curr=(mini+curr)//2
    elif x>=k:
        mini=curr
        curr=math.ceil((maxi+curr)/2)
out=""
i=0
index=0
curry=stuff[0][0]
while i<k:
    curry-=curr
    out+=str(stuff[index][1])+" "
    if curry<curr:
        index+=1
        curry=stuff[index][0]
    i+=1
print(out)