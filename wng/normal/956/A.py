n,m=[int(k) for k in raw_input().split(" ")]
ds=[]
cols=[0]*m
rows=[0]*n
pow2=[1]
for k in range(1,51):
    pow2+=[pow2[-1]*2]
for i in range(n):
    ds+=[raw_input()]
    for j in range(m):
        if ds[i][j]=="#":
            cols[j]+=pow2[i]

d=set()
tc=0
res="Yes"
for c in cols:
    if c not in d:
        if tc&c!=0:
            res="No"
            break
        d.add(c)
        tc|=c
      #  print c,tc
        
print res