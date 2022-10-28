import random
import math
n=int(input())
primes=[]
requests=0
small=n<1000000
while requests<70:
    requests+=1
    x=random.randrange(2,min(n,1000))
    a=x*x
    if small:
        a%=n
    print("sqrt",a)
    b=int(input())
    if x!=b and x+b!=n:
        primes.append(math.gcd(n,abs(b-x)))
primes=list(set(primes))
fakeprimes=[]
for guy in primes:
    if guy!=1:
        fakeprimes.append(guy)
newprimes=[]
for i in range(9):
    for a in fakeprimes:
        for b in fakeprimes:
            c=math.gcd(a,b)
            if c!=1:
                newprimes.append(c)
    fakeprimes+=newprimes
    fakeprimes=list(set(fakeprimes))
bad=[]
for a in fakeprimes:
    for b in fakeprimes:
        if a!=b:
            if a%b==0:
                bad.append(a)
realprimes=[]
for guy in fakeprimes:
    if guy not in bad:
        realprimes.append(guy)
out=""
for guy in realprimes:
    out+=str(guy)+" "
print("!",len(realprimes),out)