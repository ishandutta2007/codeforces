import sys

def getw(i, j):
    res = 0
    if j == 3 or j == 4:
        res = 2
    else:
        res = 1
    if i < 4:
        res = res + 1
    if i < 2:
        res = res + 1
    return res

id = 0
w = 0
kek = []

for line in sys.stdin:
    kek.append(line)

for i in range(6):
    for j in range(8):
        if j == 2 or j == 5:
            continue
        if kek[i][j] == '*':
            continue
        w = max(w, getw(i, j))
        
was = False
for i in range(6):
    out = ""
    for j in range(8):
        if j == 2 or j == 5:
            out = out + kek[i][j]
            continue
        if was == True:
            out = out + kek[i][j]
            continue
        if kek[i][j] == '*':
            out = out + kek[i][j]
            continue
        if getw(i, j) == w:
            was = True
            out = out + 'P'
        else:
            out = out + kek[i][j]
    print(out)