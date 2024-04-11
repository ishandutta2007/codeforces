#!/home/umqra/anaconda3/bin/python3

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(a, b)

L = 1
for i in range(2, 11):
    L = lcm(L, i)
n = int(input())
print(n // L)