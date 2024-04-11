import sys
I = lambda: [*map(int, sys.stdin.readline().split())]

def pow2(n, mul):
    if n == 2:
        return [[], [mul, 2 * mul]]
    elif n == 1:
        return [[], [mul]]
    elif n == 0:
        return [[], []]
    i = 1
    while 2 * i < n:
        i *= 2
    comb = []
    out = []
    if n == 2 * i:
        out.append(n * mul)
        big = n - 1
    else:
        big = n
    diff = 1
    out.append(i * mul)
    while i + diff <= big:
        comb.append((mul * (i + diff), mul * (i - diff)))
        out.append(2 * mul * i)
        diff += 1

    #print(comb, out, n, mul)
    a, b = pow2(diff - 1, 2 * mul)
    comb.extend(a)
    out.extend(b)
    a, b = pow2(i - diff, mul)
    comb.extend(a)
    out.extend(b)

    return [comb, out]

t, = I()
for _ in range(t):
    n, = I()
    if n == 2:
        print(-1)
        continue
    else:
        comb, out = pow2(n, 1)
        #print(comb)
        #print(out)
        count = {1 << i: 0 for i in range(17)}
        count[0] = 0
        for guy in out:
            count[guy] += 1
        big = max(out)
        curr = 1
        #print(count)
        while 2 * curr < big:
            for i in range(count[curr] // 2):
                comb.append((curr, curr))
                count[2 * curr] += 1
                count[0] += 1
            for i in range(count[curr] % 2):
                comb.append((curr, 2 * curr))
                comb.append((curr, 3 * curr))
                count[4 * curr] += 1
            curr *= 2
        #print(count)
        for i in range(count[curr] // 2):
            comb.append((curr, curr))
            count[2 * curr] += 1
            count[0] += 1
        for i in range(count[curr] % 2):
            comb.append((curr, 0))
            comb.append((curr, curr))
            count[2 * curr] += 1
        for i in range(count[0]):
            comb.append((2 * curr, 0))
        print(len(comb))
        for guy in comb:
            print(*guy)