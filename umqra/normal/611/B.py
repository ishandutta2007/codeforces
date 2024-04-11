a, b = map(int, input().split())

ans = 0
for l in range(1, 70):
    for pos in range(l - 1):
        x = 2 ** l - 1 - 2 ** pos
        if a <= x <= b:
            ans += 1
print(ans)