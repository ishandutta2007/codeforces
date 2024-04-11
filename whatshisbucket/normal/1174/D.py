n,x=map(int,input().split())
if x>=2**n:
    print(2**n-1)
    print(*([1]+[i^(i+1) for i in range(1,2**n-1)]))
else:
    print(2**(n-1)-1)
    if n==1:
        exit()
    a=[]
    bad=[0]*(2**n)
    bad[0],bad[x]=1,1
    for i in range(2**n):
        if bad[i]==0:
            a.append(i)
            bad[i]=1
            bad[i^x]=1
    print(*([a[0]]+[a[i]^a[i+1] for i in range(len(a)-1)]))