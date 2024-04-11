from sys import stdin
from math import gcd
input = stdin.readline
 
def ask(l, r):
    print(f'? {l} {r}', flush=True)
    return int(input())
n = int(input())
a = [0] * n
x, y, z = ask(1, 2), ask(2, 3), ask(1, 3)
a[1] = x + y - z
a[0] = x - a[1]
a[2] = y - a[1]
for i in range(3, n):
    a[i] = ask(i, i + 1) - a[i - 1]
print('!', *a , flush=True)