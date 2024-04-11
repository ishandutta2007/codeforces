#!/usr/bin/python3

a = int(input())
b = int(input())
c = int(input())
d = int(input())

# ^ & | WA
# ^ | & WA
# & ^ |
# & | ^
# | & ^
# | ^ &
def gand(x, y):
    return x & y
def gor(x, y):
    return x ^ y
def gxor(x, y):
    return x | y

g1 = gor(a, b)
g2 = gxor(c, d)
g3 = gand(b, c)
g4 = gor(a, d)

t1 = gand(g1, g2)
t2 = gxor(g3, g4)

res = gor(t1, t2)
print(res)