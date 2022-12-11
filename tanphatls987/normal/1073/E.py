
MOD = 998244353


def pop_count(x) :
    ans = 0
    while (x > 0) :
        ans = ans + x % 2
        x = x // 2
    return ans

def check(x, k) :
    mask = 0
    nx = int(x)
    while (nx > 0) :
        mask = mask | (1 << (nx % 10))
        nx = nx // 10
    if (pop_count(mask) <= k) :
        return x
    return 0

pop = []
p10 = []
f = [[0 for j in range(1 << 10)] for i in range(20)]
w = [[0 for j in range(1 << 10)] for i in range(20)]
def prepare() : 
    p10.append(1)
    for i in range(20) :
        p10.append(p10[i] * 10 % MOD)
    for i in range(1 << 10) :
        pop.append(pop_count(i))
    w[0][0] = 1
    for i in range(1, 20) :
        for j in range(1 << 10) :
            for use in range(10) : 
                w[i][j | (1 << use)] = (w[i][j | (1 << use)] + w[i - 1][j]) % MOD
                f[i][j | (1 << use)] = (f[i][j | (1 << use)] + w[i - 1][j] * use * p10[i - 1] + f[i - 1][j]) % MOD

def solve(x, k) :
    sx = [int(d) for d in str(x)] 
    n = len(sx) 
    ans = 0
    for i in range(1, n) :
        for use in range(1, 10) :
            for mask in range(1 << 10) : 
                if (pop[(1 << use) | mask] <= k) :
                    ans = (ans + f[i - 1][mask] + use * w[i - 1][mask] % MOD * p10[i - 1]) % MOD
    cmask = 0
    csum = 0
    for i in range(n) :
        cdig = sx[i]
        for use in range(cdig) : 
            if (i == 0 and use == 0) :
                continue
            nmask = cmask | (1 << use)
            for mask in range(1 << 10) : 
                if (pop[nmask | mask] <= k) :
                    ans = (ans + f[n - i - 1][mask] + (csum * 10 + use) * w[n - i - 1][mask] % MOD * p10[n - i - 1]) % MOD
        cmask |= 1 << cdig
        csum = (10 * csum + cdig) % MOD
    return ans

prepare()
l, r, k = map(int, input().split())
ans = (check(r, k) + solve(r, k) - solve(l, k) + MOD) % MOD
print(ans)