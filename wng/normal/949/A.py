
s=raw_input()

res=[]

isok=True
j=0
s0=set()
s1=set()
rr=[]

for k in s:
    j+=1
   #print k, res
    if k=="0":
        if s1:
            a=s1.pop()
            rr[a]+=[j]
        else:
            rr+=[[j]]
            a=len(rr)-1
        s0.add(a)
    else:
        if s0:
            a=s0.pop()
            rr[a]+=[j]
            s1.add(a)
        else:
            res=None
            break

if s1:
    res=None

if res is None:
    print -1
else:
    print len(rr)
    for i in rr:
        print len(i), " ".join([str(k) for k in i])