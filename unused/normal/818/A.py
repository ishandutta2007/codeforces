n, k = map(int, input().split())
lo, hi, ans = 1, n, 0

while lo <= hi:
    mid = (lo + hi) // 2
    if mid * (k + 1) * 2 <= n:
        ans = mid
        lo = mid + 1
    else:
        hi = mid - 1
print('%d %d %d' % (ans, ans * k, n - ans * (k + 1)))