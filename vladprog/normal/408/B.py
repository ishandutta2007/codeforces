a={}
for c in input():
    if c not in a:
        a[c]=0
    a[c]+=1
b={}
for c in input():
    if c not in b:
        b[c]=0
    b[c]+=1
res=0
for c in b:
    if c not in a:
        print(-1)
        exit()
    res+=min(a[c],b[c])
print(res)