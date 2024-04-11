import math
 
def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x%y)
 
def lcm(x, y):
    return int( x / gcd(x, y) * y )
 
n,m=[int(x) for x in input().split()]
 
print(lcm(n, 10**m))