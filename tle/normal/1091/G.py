from sys import *
import random
def miller_rabin(n):
    """
    Check n for primalty:  Example:

    >miller_rabin(162259276829213363391578010288127)    #Mersenne prime #11
    True

    Algorithm & Python source:
    http://en.literateprograms.org/Miller-Rabin_primality_test_(Python)
    """
    d = n - 1
    s = 0
    while d % 2 == 0:
        d >>= 1
        s += 1
    for repeat in range(20):
        a = 0
        while a == 0:
            a = random.randrange(n)
        if not miller_rabin_pass(a, s, d, n):
            return False
    return True

def miller_rabin_pass(a, s, d, n):
    a_to_power = pow(a, d, n)
    if a_to_power == 1:
        return True
    for i in range(s-1):
        if a_to_power == n - 1:
            return True
        a_to_power = (a_to_power * a_to_power) % n
    return a_to_power == n - 1

def gcd(a,b):
    if a==b:
        return a
    if a==0:
        return b
    if b==0:
        return a
    if (a&1)==0:
        if (b&1)==1:
            return gcd(a>>1,b)
        else:
            return gcd(a>>1,b>>1)<<1
    else:
        if (b&1)==0:
            return gcd(a,b>>1)
        elif a>b:
            return gcd((a-b)>>1,b)
        else:
            return gcd((b-a)>>1,a)

n=int(raw_input())
ps=[n]
for g in xrange(0,98):
    g=random.randint(2,n-1)
    print 'sqrt '+str(g*g%n)
    stdout.flush()
    h=int(raw_input())
    if h==-1:
        continue
    g-=h
    if g<0:
        g=-g
    g=gcd(g,n)
    s=[]
    for p in ps:
        t=gcd(g,p)
        if t!=1 and t!=p:
            s.append(t)
            s.append(p/t)
        else:
            s.append(p)
    ps=s
print '! '+str(len(ps))+' '+' '.join(map(str,ps))
stdout.flush()