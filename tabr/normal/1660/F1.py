tt = int(input())
for _ in range(tt):
    n = int(input())
    s = input()
    ans = 0
    pref = [0] * (n + 1)
    for i in range(n):
        pref[i + 1] = pref[i]
        if s[i] == '+':
            pref[i + 1] -= 1
        else:
            pref[i + 1] += 1
    fenw = [[0] * (2 * n + 10) for i in range(3)]
    def fenwadd(i, p, x):
        p += 1
        while p <= 2 * n + 10:
            fenw[i][p - 1] += x
            p += p & -p
    def fenwsum(i, r):
        res = 0
        while (r > 0):
            res += fenw[i][r - 1]
            r -= r & -r
        return res
    for i in range(n + 1):
        mod3 = (3 + pref[i] % 3) % 3
        c = (pref[i] - mod3) // 3 + n
        ans += fenwsum(mod3, c + 1)
        fenwadd(mod3, c, 1)
    print(ans)