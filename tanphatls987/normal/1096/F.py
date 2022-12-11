MOD = 998244353
def power(x, n) :
    ans = 1
    while (n) :
        if ((n & 1) == 1) :
            ans = ans * x % MOD
        x = x * x % MOD
        n = n // 2
    return ans

n = int(input())
a = list(map(int, input().split()))
b = [0 for i in range(n + 1)]

def add(x, v) :
    while (x <= n) : 
        b[x] = b[x] + v
        x = x + (x & -x)
def get(x) :
    ans = 0
    while (x) :
        ans = ans + b[x]
        x = x - (x & -x)
    return ans

anss = 0
for i in range(n) :
    if (a[i] != -1) :
        add(a[i], 1)
        anss = anss + get(n) - get(a[i])

anss = anss % MOD
total = 0

sur = [0] + [1 for i in range(n)]
for i in range(n) :
    if (a[i] == -1) :
        total = total + 1
    else :
        sur[a[i]] = 0

if (total == 0) : 
    print(anss) 
    exit(0)
for i in range(1, n + 1) : 
    sur[i] = sur[i] + sur[i - 1]

dead = 0

ansa = 0
for i in range(n) :
    if (a[i] != -1) :
        ansa = ansa + sur[a[i]] * (total - dead) + (sur[n] - sur[a[i]]) * dead
    else : 
        dead = dead + 1

ans = (ansa * 4 + anss * 4 * total + total * total * (total - 1)) % MOD
ans = (ans * power(4 * total, MOD - 2)) % MOD
print(ans)