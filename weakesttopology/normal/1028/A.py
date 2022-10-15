n, m = map(int, input().split())
s = [input() for i in range(n)]

opt = 0
iopt, jopt = -1, -1

for i in range(n):
    for j in range(m):
        k = 0
        while i + k < n and j + k < m and s[i + k][j + k] == 'B':
            k += 1
        if k > opt:
            opt = k
            iopt = i + k // 2
            jopt = j + k // 2

print(iopt + 1, jopt + 1)