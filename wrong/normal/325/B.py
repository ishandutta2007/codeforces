def large_sqrt(x):
    lo, hi = 0, x + 1
    while hi - lo > 1:
        mid = (hi + lo) / 2
        if mid ** 2 <= x:
            lo = mid
        else:
            hi = mid
    if lo ** 2 == x:
        return lo
    return -1

N = input()
res = []

for k in range(0, 80):
    A, B, C = 1, 2**(k+1)-3, -2*N
    D = B*B - 4*A*C
    if D < 0:
        continue

    rD = large_sqrt(D)
    if rD < 0:
        continue

    sol1 = -B + rD
    sol2 = -B - rD

    if sol1 % 2 == 0 and (sol1 / 2) % 2 == 1 and sol1 > 0:
        res.append(2**k * (sol1 / 2))
    if sol2 % 2 == 0 and (sol2 / 2) % 2 == 1 and sol2 > 0:
        res.append(2**k * (sol2 / 2))

res = sorted(list(set(res)))
for r in res:
    print r

if len(res) == 0:
    print -1