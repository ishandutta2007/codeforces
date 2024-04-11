x, y, m = map(int, input().split())

if max(x, y) < m and max(x, y) <= 0:
    print(-1)
    exit()

ans = 0
while max(x, y) < m:
    if x < y:
        x, y = y, x

    if y < 0:
        k = (abs(y) + x - 1) // x
        ans += k
        y += k * x
    else:
        y += x
        ans += 1

print(ans)