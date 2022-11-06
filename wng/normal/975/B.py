b=[int(k) for k in raw_input().split(" ")]

res=0
for i in range(14):
    a=b[:]
    ai=a[i]
    left=ai%14
    a[i]=0
    for j in range(left):
        a[(i+1+j)%14]+=1
    for j in range(14):
        a[j]+=ai/14
    tr=0
    for j in range(14):
        if not a[j]%2:
            tr+=a[j]
    res=max(res,tr)
        
print res