n=int(input())
both=[]
a=[]
b=[]
neither=[]
for i in range(n):
    c,d=map(int,input().split())
    if c==11:
        both.append(d)
    elif c==10:
        a.append(d)
    elif c==1:
        b.append(d)
    else:
        neither.append(d)
inf=sum(both)
lee=len(both)
a.sort(reverse=True)
b.sort(reverse=True)
x=min(len(a),len(b))
inf+=sum(a[:x])+sum(b[:x])
neither+=a[x:]+b[x:]
neither.sort(reverse=True)
if len(neither)<lee:
    inf+=sum(neither)
else:
    inf+=sum(neither[:lee])
print(inf)