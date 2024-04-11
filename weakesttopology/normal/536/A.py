A, B, n = map(int, input().split())

def s(i):
    return A + i * B

def f(r):
    return r * A + r * (r - 1) // 2 * B

for i in range(n):
    l, t, m = map(int, input().split())
    ans = -1
    if s(l - 1) <= t:
        L, R = l, 10 ** 6 + 1
        while L + 1 < R:
            M = (L + R) // 2
            if f(M) - f(l - 1) <= t * m and s(M - 1) <= t:
                L = M
            else:
                R = M
        ans = L

    print(ans)