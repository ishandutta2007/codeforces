a, b = map(int, raw_input().split())
ans = 1
if b >= 2:
    ans += a * (a - 1) / 2
    if b >= 3:
        ans += a * (a - 1) * (a - 2) / 3
        if b >= 4:
            ans += a * (a - 1) * (a - 2) * (a - 3) / 4 / 3 / 2 / 1 * 6
            ans += a * (a - 1) / 2 * (a - 2) * (a - 3) / 2 / 2
print ans