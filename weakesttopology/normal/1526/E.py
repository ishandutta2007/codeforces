n, k = map(int, input().split())
p = list(map(int, input().split()))

pos = [-1] * (n + 1)
for i, x in enumerate(p):
    pos[x] = i

d = 0
for i in range(n - 1):
    if pos[p[i + 1] + 1] < pos[p[i] + 1]:
        d += 1

if k <= d:
    print(0)
    exit()

mod = 998244353

def modpow(x, p):
    res = 1
    while p:
        if p % 2:
            res = res * x % mod
        x = x * x % mod
        p //= 2
    return res

def C(N, K):
    num = 1
    den = 1
    for j in range(K):
        num *= N - j
        num %= mod
        den *= K - j
        den %= mod
    return num * modpow(den, mod - 2) % mod

k -= 1
ans = C(n + k - d, n)
print(ans)