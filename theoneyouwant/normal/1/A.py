import sys
from math import ceil

n,m,a = map(int,input().split())
a1 = ceil(n/a)
a2 = ceil(m/a)
print(a1*a2)