from fractions import gcd
def lcm(n,m):
    return (n*m)//gcd(n,m)
a,b,c = map(int,input().split())
print(c//lcm(a,b))