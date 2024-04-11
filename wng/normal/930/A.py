
n=int(raw_input())
p=[int(k) for k in raw_input().split(" ")]

d={}
d[1]=0

def filld(a):
    global d
    if p[a-2] not in d:        
        d[a-2]=filld(p[a-2])
    d[a]=d[p[a-2]]+1
    return d[a]

res=0

ds={0:1}
for k in range(2,n+1):
    if k not in d:
        filld(k)
    if d[k] not in ds:
        ds[d[k]]=0
    ds[d[k]]+=1
    
for i in ds:
    res+=ds[i]%2

print res