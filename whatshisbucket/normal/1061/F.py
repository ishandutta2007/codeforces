import random
import math
n,k=map(int,input().split())
height=math.floor(math.log10(n)/math.log10(k))
powers=[1]
for i in range(1,12):
    powers.append(powers[-1]+k**i)
end1=1
end2=2
def findlevels(a,b):
    under1=[]
    under2=[]
    for i in range(n):
        print("?",i+1,a,b)
        if input()=="Yes":
            under1.append(i+1)
        print("?",i+1,b,a)
        if input()=="Yes":
            under2.append(i+1)
    if len(under1) in powers:
        level1=math.floor(math.log10(len(under1))/math.log10(k))
    else:
        level1=math.floor(math.log10(n-len(under1))/math.log10(k))+1
    if len(under2) in powers:
        level2=math.floor(math.log10(len(under2))/math.log10(k))
    else:
        level2=math.floor(math.log10(n-len(under2))/math.log10(k))+1
    return([level1,level2])
while True:
    a=random.randrange(n)+1
    b=random.randrange(n)+1
    while b==a:
        b=random.randrange(n)+1
    path=[]
    for i in range(n):
        print("?",a,i+1,b)
        if input()=="Yes":
            path.append(i+1)
    if len(path)>=2*height:
        break
levels=[]
for i in range(int(len(path)/2)):
    levels+=findlevels(path[2*i],path[2*i+1])
if len(path)%2==1:
    levels.append(findlevels(path[-1],path[-2])[0])
top=max(levels)
for i in range(len(path)):
    if levels[i]==top:
        topvertex=path[i]
        break
print("!",topvertex)