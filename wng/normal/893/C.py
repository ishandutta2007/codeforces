n,m=[int(k) for k in raw_input().split(" ")]

c=[int(k) for k in raw_input().split(" ")]
d={}


for j in range(m):
    a,b=[int(k) for k in raw_input().split(" ")]
    for k in [a,b]:
        ot=a+b-k
        if k not in d:
            d[k]=set()
        d[k].add(ot)

mnb=10**9+10 #initialisation

stack=[0]*(n+1)
bs=0
es=0
used=[0]*(n+1)
res=0
for k in range(1,n+1):
    if not used[k]:
        stack[es]=k
        used[k]=1
        es+=1
        mm=mnb
        while bs!=es:
            j=stack[bs]
            mm=min(mm,c[j-1])
            if j in d:
                for i in d[j]:
                    if not used[i]:
                        stack[es]=i
                        used[i]=1
                        es+=1
            bs+=1
       # print k,stack,mm
        res+=mm

print res