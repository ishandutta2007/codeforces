import math
n=int(input())
factordict={}
superfactors={}
inputs=[]
for i in range(n):
    inputs.append(int(input()))
for guy in inputs:
    if guy==round(guy**0.5)**2:
        if guy==round(guy**0.25)**4:
            a=round(guy**0.25)
            if a in factordict:
                factordict[a]+=4
            else:
                factordict[a]=4
        else:
            a=round(guy**0.5)
            if a in factordict:
                factordict[a]+=2
            else:
                factordict[a]=2
    elif guy==round(guy**(1/3))**3:
        a=round(guy**(1/3))
        if a in factordict:
            factordict[a]+=3
        else:
            factordict[a]=3
    else:
        j=0
        for guy2 in inputs:
            b=math.gcd(guy,guy2)
            if b>1 and not guy==guy2:
                if b in factordict:
                    factordict[b]+=1
                else:
                    factordict[b]=1
                if guy//b in factordict:
                    factordict[guy//b]+=1
                else:
                    factordict[guy//b]=1
                j=1
                break
        if j==0:
            if guy in superfactors:
                superfactors[guy]+=1
            else:
                superfactors[guy]=1
prod=1
for guy in factordict:
    prod*=(factordict[guy]+1)
    prod=prod%998244353
for guy in superfactors:
    prod*=(superfactors[guy]+1)**2
    prod=prod%998244353
print(prod)