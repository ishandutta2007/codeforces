n, m = map(int, raw_input().split())
mat = [map(int, raw_input().split()) for i in range(n)]

i0, j0 = 0, 0
for i in range(n):
    for j in range(m):
        if mat[i][j] < mat[i0][j0]:
            i0, j0 = i, j

i1 = 0
for i in range(n):
    if mat[i][j0] > mat[i1][j0]:
        i1 = i
j1 = 0
for j in range(m):
    if mat[i0][j] > mat[i0][j1]:
        j1 = j


vM = (mat[i0][j1] + mat[i1][j0]) - (mat[i0][j0] + mat[i1][j1])
if vM == 0:
    vM = 10 ** 18

a = [mat[i][j0] for i in range(n)]
b = [(mat[i0][j] + vM - mat[i0][j0]) % vM for j in range(m)]

for i in range(n):
    for j in range(m):
        if (a[i] + b[j]) % vM != mat[i][j]:
            print 'NO'
            exit()

print 'YES'
print vM
print ' '.join(map(str, a))
print ' '.join(map(str, b))