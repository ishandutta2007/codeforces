from functools import *
from random import *
from math import *
import sys

n = int(input())
p = {n}
for _ in range(50):
    x = randint(1,n-1)
    print('sqrt %d' % (x*x%n))
    x = x + int(input())
    sys.stdout.flush()
    p = set(reduce(list.__add__, [[gcd(a,x), a//gcd(a,x)] for a in p] ))
print('!',len(p)-1,' '.join([str(x) for x in p-{1}]))