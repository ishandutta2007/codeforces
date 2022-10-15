import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

S = sum(a)
primes = []

res = 10 ** 100

if S == 1:
    res = -1

for p in range(2, S):

    if p * p > S:
        break

    if S % p == 0:
        primes.append(p)
        while S % p == 0:
            S //= p

if S > 1:
    primes.append(S)


for p in primes:

    cost = 0
    ct = 0

    for x in a:
        ct = (ct + x) % p
        cost += min(ct, p - ct);

        if cost > res:
            break

    res = min(res, cost)


print(res)