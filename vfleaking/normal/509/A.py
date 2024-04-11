n = input()

f = [[1] * n]

for i in range(1, n):
    f.append([0] * n)
    f[i][0] = 1
    for j in range(1, n):
        f[i][j] = f[i - 1][j] + f[i][j - 1]
print f[-1][-1]