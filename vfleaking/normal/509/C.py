n = input()
b = [int(raw_input()) for i in range(n)]

a = []

lastb = 0
for curb in b:
    d = curb - lastb
    p = 0
    while True:
        if p == len(a):
            a.append(0)
        if a[p] < 9 and 1 <= d <= 9 * p + 9 - a[p]:
            d -= 1
            a[p] += 1
            q = 0
            while q < p:
                if d <= 9:
                    a[q] = d
                    break
                a[q] = 9
                d -= 9
                q += 1
            if q == p:
                a[p] += d
            break
        d += a[p]
        a[p] = 0
        p += 1
    lastb = curb
    print ''.join(map(str, reversed(a)))