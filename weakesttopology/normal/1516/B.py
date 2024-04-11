t = int(input())
for z in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    good = False
    pref = 0
    for i in range(n - 1):
        pref ^= a[i]

        cur = 0
        found = False
        for j in range(i + 1, n):
            cur ^= a[j]
            if cur == pref:
                cur = 0
                found = True
        if cur == 0 and found:
            good = True
            break

    print('YES' if good else 'NO')