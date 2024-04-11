n,k,M,D=[int(k) for k in raw_input().split(" ")]

res=0
for d in range(D,0,-1):
    minpourd=0
    s=1<<60
    while s:
        totest=(minpourd+s)
        nbguys=(n/totest)
        if totest<=n and (nbguys-1)/k>(d-1):
            minpourd=totest
        s>>=1
    minpourd+=1
    maxpourd=0
    s=1<<60
    while s:
        totest=(maxpourd+s)
        nbguys=(n/totest)
        if totest<=n and (nbguys-1)/k>=(d-1):
            maxpourd=totest
        s>>=1
 #  print d,maxpourd,minpourd
    if minpourd>M:
        break
    else:
        if maxpourd>=M:
            res=max(res,M*(d))
        else:
            res=max(res,maxpourd*(d))
print res