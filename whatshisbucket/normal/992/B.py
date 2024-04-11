l,r,x,y=map(int,input().split())
if y%x!=0:
    print(0)
else:
    z=y//x
    primes=[]
    i=2
    while i<=z**0.5:
        if z%i==0:
            primes.append(i)
            z//=i
        else:
            i+=1
    if z>1:
        primes.append(z)
    prim=set(primes)
    prime=[guy**primes.count(guy) for guy in prim]
    z=y//x
    tot=0
    for i in range(2**len(prime)):
        prod=1
        strin=bin(i)[::-1]+"0"*20
        for j in range(len(strin)):
            if strin[j]=="1":
                prod*=prime[j]
        if l<=x*prod<=r and l<=x*(z//prod)<=r:
            tot+=1
    print(tot)