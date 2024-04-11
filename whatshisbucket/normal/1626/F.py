import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

n, a0, x, y, k, M = I()

big = 720720
mod = [0] * big
mod[a0 % big] += 1
tot = a0
for i in range(n - 1):
    a0 = (a0 * x + y) % M
    tot += a0
    mod[a0 % big] += 1

m = 998244353
total = 0
for i in range(k):
    total += tot
    if i < k - 1:
        tot *= n
        tot %= m
        total *= n
        total %= m
        change = [0] * big
        for j in range(big):
            x = mod[j]
            change[j - j % (i + 1)] += x
            change[j] -= x
            tot -= x * (j % (i + 1))
        for j in range(big):
            mod[j] = (n * mod[j] + change[j]) % m
print(total % m)