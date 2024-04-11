q = int(input())
for _ in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = [0] * n
    for i in range(n):
        c[i] = b[i] - a[i]
    flg = 0
    ok = 1
    for i in range(n):
        if flg == 1:
            if c[i] != val and c[i] != 0:
                ok = 0
                break
            elif c[i] == 0:
                flg = 2
        elif flg == 0:
            if c[i] != 0:
                flg = 1
                val = c[i]
                if val < 0:
                    ok = 0
                    break
        elif flg == 2:
            if c[i] != 0:
                ok = 0
                break
    if ok:
        print('YES')
    else:
        print('NO')