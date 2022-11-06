n,p=[int(k) for k in input().split(" ")]

def cb(n):
    res=0
    while n:
        if n%2:
            res+=1
        n>>=1
    return res


k=0
res=-1
while (n-k*p>0):
    nbb=cb(n-k*p)
    if nbb<=k and n-k*p>=k:
        res=k
        break
    k+=1

print(res)