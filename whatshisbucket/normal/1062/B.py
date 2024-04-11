import math
n=int(input())
if n==1:
    print(1,0)
else:
    factors=[]
    for i in range(1,round(n**0.5)+2):
        if n%i==0:
            factors+=[i,n//i]
    factors=list(set(factors))
    def isprime(n):
        if n==1:
            return False
        if n<4:
            return(True)
        for i in range(2,round(n**0.5)+2):
            if n%i==0:
                return False
        return True
    primes=[]
    for factor in factors:
        if isprime(factor):
            primes.append(factor)
    exps=[]
    for prime in primes:
        x=prime
        expo=0
        while n%x==0:
            x*=prime
            expo+=1
        exps.append(expo)
    b=max(exps)
    decs=math.ceil(math.log2(b))
    cheat=True
    exp=2**decs
    for guy in exps:
        if guy!=exp:
            cheat=False
            break
    prod=1
    for guy in primes:
        prod*=guy
    if cheat:
        print(prod,decs)
    else:
        print(prod,decs+1)