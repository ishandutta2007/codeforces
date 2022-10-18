import sys

def extGCD(a, b, xa, xb):
    if (b == 0):
        return a, xa
    q = a//b
    return extGCD(b, a-q*b, xb, xa-q*xb)

# stdin = open("input.txt", "r")
a, b, c = map(int, input().split())
c = -c

d, x = extGCD(a, b, 1, 0)

if (c%d != 0):
    print(-1)
else:
    x *= c//d
    if (b == 0):
        y = 0
    else:
        y = (c-x*a)//b
    print(x, y)