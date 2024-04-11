from functools import reduce
from math import gcd

_, k = map(int, input().split())
g = reduce(gcd, [k] + list(map(int, input().split())))
print(k // g)
print(" ".join(str(l) for l in range(0, k, g)))