n, m = map(int, input().split())
a = [[x for x in input()] for _ in range(n)]
i = 0
j = 0
ans = 0
while True:
    found = False
    for x in range(100):
        for t in range(0, x + 1):
            ni = i + t
            nj = j + x - t
            if ni < n and nj < m and a[ni][nj] == '*':
                ans += 1
                found = True
                i = ni
                j = nj
                a[ni][nj] = '.'
                break
        if found:
            break
    if not found:
        break
print(ans)