from math import gcd
t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    cnt = [0, 0]
    freq = {}
    ans = [0] * n
    for i, x in enumerate(s):
        x = 1 if x == s[0] else 0
        cnt[x] += 1
        g = gcd(*cnt)
        f = (cnt[0] // g) / (cnt[1] // g)
        ans[i] = freq[f] = freq.get(f, 0) + 1
    print(*ans)