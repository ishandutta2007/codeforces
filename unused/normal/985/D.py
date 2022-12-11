def check(n, h, t):
    if t < h:
        return n <= t * (t + 1) // 2

    if n <= h * (h - 1) // 2:
        return True

    n -= h * (h - 1) // 2
    t -= h - 1

    if t % 2 == 0:
        upper = t // 2 * (t // 2 + 1)
        lower = (h - 1) * t
        return n <= upper + lower
    else:
        upper = (t // 2 + 1) * (t // 2 + 1)
        lower = (h - 1) * t
        return n <= upper + lower

n, h = map(int, input().split())

lo, hi, ans = 1, n - 1, n
while lo <= hi:
    mid = (lo + hi) >> 1
    if check(n, h, mid):
        ans = mid
        hi = mid - 1
    else:
        lo = mid + 1

print(ans)