from itertools import permutations

n, m = map(int, input().split())

def S(x):
    if x == 0:
        return 1
    res = 0
    while x > 0:
        x //= 7
        res += 1
    return res


a, b = S(n - 1), S(m - 1)

if a + b > 7:
    print(0)
    exit()

D = list(range(7))

res = 0

for v in permutations(D, a):

    x = 0
    for i in range(a):
        x = 7 * x + v[i]

    if x >= n:
        continue

    R = [d for d in D if d not in v]

    for u in permutations(R, b):
        y = 0
        for i in range(b):
            y = 7 * y + u[i]

        res += y < m

print(res)