import math
n=int(input())
b=[]
c=[]
for i in range(n):
    a=float(input())
    c.append(a)
    if(abs(math.trunc(c[i])-c[i])<0.000001):
        b.append(round(a))
        continue
    if(a>0):
        b.append(math.trunc(a))
    elif(a<0):
        b.append(math.trunc(a)-1)
    else:
        b.append(0)
x=sum(b)
i=0
while(x<0):
    if(abs(math.trunc(c[i])-c[i])<0.000001):
        i+=1
    else:
        b[i]+=1
        i+=1
        x+=1
for i in range(n):
    print(b[i])