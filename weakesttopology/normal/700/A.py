n, l, v1, v2, k = map(int, input().split())

if k >= n:
    res = l / v2
else:
    L, R = 0, l / v2
    x = (n + k - 1) // k

    for i in range(100):
        M = (L + R) / 2

        first = M + (l - v2 * M) / v1

        prev_cost = (x - 1) * (M + M * (v2 - v1) / (v1 + v2))
        last = prev_cost + (l - v1 * prev_cost) / v2

        if last > first:
            R = M
        else:
            L = M

    res = (l - L * v2) / v1 + L

print('{:0.10f}'.format(res))