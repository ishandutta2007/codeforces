n,x=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]
nbx=[0]*(x+1)
nbrex=[0]*(x+1)
a=sorted(a)

res=None
for i in range(n):
    axx=a[i]&x
    if i and a[i]==a[i-1]:
        res=0
        break
    if axx==a[i]:
        nbrex[a[i]]+=1
    nbx[axx]+=1

if res is None:
    if max(nbx)<2:
        print -1
    else:
        for i in range(x+1):
            if nbx[i]>1 and nbrex[i]:
                res=1
                break
        if res is None:
            print 2
        else:
            print 1
else:
    print res