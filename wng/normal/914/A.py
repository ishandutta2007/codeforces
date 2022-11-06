#[int(k) for k in raw_input().split(" ")]

import math

def issq(k):
    if k<0:
        return False
    return int(math.sqrt(k+0.01))**2==k
    

n=int(raw_input())
a=[int(kk) for kk in raw_input().split(" ")]

for k in sorted(a,reverse=True):
    if not issq(k):
        print k
        break