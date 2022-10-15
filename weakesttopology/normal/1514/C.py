from math import gcd

n = int(input())

units = [x for x in range(1, n) if gcd(n, x) == 1]

prod = 1
for x in units:
    prod = x * prod % n

if prod != 1:
    units.remove(prod)

print(len(units))
print(*units)