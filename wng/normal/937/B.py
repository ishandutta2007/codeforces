
def gen_primes(n):
    """ Generate prime numbers until n
    """
    # Maps composites to primes witnessing their compositeness.
    # This is memory efficient, as the sieve is not "run forward"
    # indefinitely, but only as long as required by the current
    # number being tested.
    #
    D = {}
    Dr={}
    
    # The running integer that's checked for primeness
    q = 2
    while q<=n:
        if q not in D:
            # q is a new prime.
            # Yield it and mark its first multiple that isn't
            # already marked in previous iterations
            #
            Dr[q]=None
            D[q * q] = [q]
        else:
            # q is composite. D[q] is the list of primes that
            # divide it. Since we've reached q, we no longer
            # need it in the map, but we'll mark the next 
            # multiples of its witnesses to prepare for larger
            # numbers
            # 
            for p in D[q]:
                D.setdefault(p + q, []).append(p)
            del D[q]
        q += 1
    return Dr.keys()



def isprime(n,primesorted):
    j=0
    i=0
    while n>1 and i*i<n and j<len(primesorted):
        i=primesorted[j]
        if n%i==0:
            return 0
        j+=1
    return 1

def isqrt(x):
    if x < 0:
        raise ValueError('square root not defined for negative numbers')
    n = int(x)
    if n == 0:
        return 0
    a, b = divmod(n.bit_length(), 2)
    x = 2**(a+b)
    while True:
        y = (x + n//x)//2
        if y >= x:
            return x
        x = y
        
p,y=[int(k) for k in raw_input().split(" ")]

sy=isqrt(y)

ps=sorted(gen_primes(min(sy,p)))

res=-1
cd=y
while cd>p:
    if isprime(cd,ps):
        res=cd
        break
    cd-=1

print res