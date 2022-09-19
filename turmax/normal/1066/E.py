x,y=map(int,input().split())
b1=str(input())
d1=[]
for i in b1:
    d1.append(int(i))
b2=str(input())
d2=[]
for i in b2:
    d2.append(int(i))
if(x>y):
    u=list()
    for t in range(y,0,-1):
        u.append(d1[-t])
    d1=u
    x=y
m=[1]
for i in range(x-1):
    m.append((m[-1]*2)%998244353)
s=0
f=[]
f.append(sum(d2[0:(y-x+1):1]))
t=y-x+1
while True:
    try:
        f.append(f[-1]+d2[t])
        t+=1
    except:
        break
for i in range(x):
    s+=(d1[i]*m[-i-1]*f[i])
    s=s%998244353
print(s)