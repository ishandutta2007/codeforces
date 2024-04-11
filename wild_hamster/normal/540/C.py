n,m = map(int, input().split())
a = []
for i in range(n):
    a.append([])
for i in range(n):
    c = input()
    for j in c:
        if (j == '.'):
            a[i].append(0)
        else:
            a[i].append(1)
x1,y1 = map(int,input().split())
x2,y2 = map(int,input().split())
x1 -= 1
y1 -= 1
x2 -= 1
y2 -= 1
a[x1][y1] = 0
f = []
qs = 0
qt = 1
f.append([x1,y1])
while (qs < qt):
    x = f[qs][0]
    y = f[qs][1]
    if ([x,y] == [x2,y2]):
        break
    a[x][y] = 1
    qs += 1
    if (x < n-1 and (a[x+1][y] == 0 or [x+1,y] == [x2,y2])):
        qt += 1
        f.append([x+1,y])
        if ([x+1,y] == [x2,y2]):
            break;
        a[x+1][y] += 2
    if (x > 0 and (a[x-1][y] == 0 or [x-1,y] == [x2,y2])):
        qt += 1
        f.append([x-1,y])
        if ([x-1,y] == [x2,y2]):
            break;
        a[x-1][y] += 2
    if (y < m-1 and (a[x][y+1] == 0 or [x,y+1] == [x2,y2])):
        qt += 1
        f.append([x,y+1])
        if ([x,y+1] == [x2,y2]):
            break;
        a[x][y+1] += 2
    if (y > 0 and (a[x][y-1] == 0 or [x,y-1] == [x2,y2])):
        qt += 1
        f.append([x,y-1])
        if ([x,y-1] == [x2,y2]):
            break;
        a[x][y-1] += 2
else:
    print('NO')
    exit(0)
if (a[x2][y2] == 1):
    print('YES')
else:
    #print(a[x2-1][y2],a[x2][y2-1])
    if (x2 > 0 and a[x2-1][y2] != 1):
        print('YES')
    elif (x2 < n-1 and a[x2+1][y2] != 1):
        print('YES')
    elif (y2 < m-1 and a[x2][y2+1] != 1):
        print('YES')
    elif (y2 > 0 and a[x2][y2-1] != 1):
        print('YES')
    else:
        print('NO')