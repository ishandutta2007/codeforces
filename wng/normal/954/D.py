
n,m,s,t=[int(k) for k in raw_input().split(" ")]
s-=1
t-=1
d=[set() for k in range(n)] 
for i in range(m):
	a,b=[int(k)-1 for k in raw_input().split(" ")]
	d[a].add(b)
	d[b].add(a)

ds=[10000]*n
ds[s]=0
stack=[s]
kk=0
while kk<len(stack):
    k=stack[kk]
    kk+=1
    cu=ds[k]
    for i in d[k]:
        if ds[i]==10000:
            ds[i]=cu+1
            stack+=[i]



dt=[10000]*n
dt[t]=0
stack=[t]
kk=0
while kk<len(stack):
    k=stack[kk]
    kk+=1
    cu=dt[k]
    for i in d[k]:
        if dt[i]==10000:
            dt[i]=cu+1
            stack+=[i]

res=0
for i in range(n):
    for j in range(i+1,n):
        if i not in d[j]:
            if (min(ds[i]+dt[j]+1,ds[j]+dt[i]+1)>=ds[t]):
                res+=1
                
print res