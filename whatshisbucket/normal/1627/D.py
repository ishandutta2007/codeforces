import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

n, = I()
a = I()
A = set(a)
big = max(a)
era = [0] * 1000001
i = 2
while i <= 1000000:
    if era[i] == 0:
        k = i
        while k <= 1000000:
            era[k] = i
            k += i
    i += 1
import math
ggg = a[0]
for guy in a:
    ggg = math.gcd(ggg, guy)
factor = [0] * (big + 1)
for i in range(1, big + 1):
    primes = [era[i]]
    g = i
    while g > 1:
        if era[g] != primes[-1]:
            primes.append(era[g])
        g //= era[g]
    factor[i] = set(primes)
factor[1] = set()
tot = 0
for i in range(1, big + 1):
    if i in A or i % ggg != 0:
        continue
    f = factor[i].copy()
    k = i
    found = 0
    mult = 1
    sets = []
    extra = None
    while k <= big and (f or found < 2 or extra):
        if k in A:
            if extra is None:
                extra = factor[k] - factor[i]
            else:
                extra &= factor[k]
            found += 1
            removable = []
            for guy in f:
                if mult % guy != 0:
                    removable.append(guy)
            for g in removable:
                f.remove(g)
        k += i
        mult += 1
    if not f and not extra and found > 1:
        tot += 1
        #print(i)
 
print(tot)