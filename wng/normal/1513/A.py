#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t=int(input())
for nbt in range(t):
    n,k=[int(i) for i in input().split()]
    if k>(n-1)//2:
        print("-1")
    else:
        peaks=list(range(n-k+1,n+1))
        np= list(range(1,n-k+1))
        kk=0
        res=[]
        while kk<k:
            res+=[np[kk]]+[peaks[kk]]
            kk+=1
        res+=[" ".join(str(k) for k in np[kk:])]
        print(" ".join(str(k) for k in res))