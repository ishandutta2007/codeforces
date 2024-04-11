import math

n, k = map(int, input().split())
a = 0
x, y = map(int, input().split())
for i in range(n-1):
    p, q = map(int, input().split())
    a += math.sqrt((x - p)* (x - p) + (y - q) * (y - q))
    x,y = p,q
print(a * k / 50)