a = [list(map(int,input().split())) for _ in range(4)]
f = False
for i in a:
    if i[3]:
        f = True
if not f:
    print("NO")
else:
    p = []
    if a[0][3]:
        if a[1][0] or a[2][1] or a[3][2] or (not (a[0].count(1) == 1)):
            f = False
    if a[1][3]:
        if a[0][2] or a[2][0] or a[3][1] or (not (a[1].count(1) == 1)):
            f = False
    if a[2][3]:
        if a[0][1] or a[1][2] or a[3][0] or (not (a[2].count(1) == 1)):
            f = False
    if a[3][3]:
        if a[0][0] or a[1][1] or a[2][2] or (not (a[3].count(1) == 1)):
            f = False       
    if f:
        print("NO")
    else:
        print("YES")