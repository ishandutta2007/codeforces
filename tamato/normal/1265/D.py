def main():
    A, B, C, D = map(int, input().split())
    N = A+B+C+D

    ans = [0] * N
    a, b, c, d = A-1, B, C, D
    prev = 0
    ok = 1
    for i in range(1, N):
        if a<0 or b<0 or c<0 or d<0:
            ok = 0
            break
        if prev == 0:
            b -= 1
            ans[i] = 1
            prev = 1
        elif prev == 3:
            c -= 1
            ans[i] = 2
            prev = 2
        elif prev == 1:
            if a:
                a -= 1
                ans[i] = 0
                prev = 0
            else:
                c -= 1
                ans[i] = 2
                prev = 2
        elif prev == 2:
            if b:
                b -= 1
                ans[i] = 1
                prev = 1
            else:
                d -= 1
                ans[i] = 3
                prev = 3
    if a<0 or b<0 or c<0 or d<0:
        ok = 0
    if ok:
        print('YES')
        print(*ans)
        exit()

    ans = [0] * N
    ans[0] = 1
    a, b, c, d = A, B-1, C, D
    prev = 1
    ok = 1
    for i in range(1, N):
        if a<0 or b<0 or c<0 or d<0:
            ok = 0
            break
        if prev == 0:
            b -= 1
            ans[i] = 1
            prev = 1
        elif prev == 3:
            c -= 1
            ans[i] = 2
            prev = 2
        elif prev == 1:
            if a:
                a -= 1
                ans[i] = 0
                prev = 0
            else:
                c -= 1
                ans[i] = 2
                prev = 2
        elif prev == 2:
            if b:
                b -= 1
                ans[i] = 1
                prev = 1
            else:
                d -= 1
                ans[i] = 3
                prev = 3
    if a<0 or b<0 or c<0 or d<0:
        ok = 0
    if ok:
        print('YES')
        print(*ans)
        exit()

    ans = [0] * N
    ans[0] = 2
    a, b, c, d = A, B, C-1, D
    prev = 2
    ok = 1
    for i in range(1, N):
        if a<0 or b<0 or c<0 or d<0:
            ok = 0
            break
        if prev == 0:
            b -= 1
            ans[i] = 1
            prev = 1
        elif prev == 3:
            c -= 1
            ans[i] = 2
            prev = 2
        elif prev == 1:
            if c:
                c -= 1
                ans[i] = 2
                prev = 2
            else:
                a -= 1
                ans[i] = 0
                prev = 0
        elif prev == 2:
            if d:
                d -= 1
                ans[i] = 3
                prev = 3
            else:
                b -= 1
                ans[i] = 1
                prev = 1
    if a<0 or b<0 or c<0 or d<0:
        ok = 0
    if ok:
        print('YES')
        print(*ans)
        exit()

    ans = [0] * N
    ans[0] = 3
    a, b, c, d = A, B, C, D-1
    prev = 3
    ok = 1
    for i in range(1, N):
        if a<0 or b<0 or c<0 or d<0:
            ok = 0
            break
        if prev == 0:
            b -= 1
            ans[i] = 1
            prev = 1
        elif prev == 3:
            c -= 1
            ans[i] = 2
            prev = 2
        elif prev == 1:
            if c:
                c -= 1
                ans[i] = 2
                prev = 2
            else:
                a -= 1
                ans[i] = 0
                prev = 0
        elif prev == 2:
            if d:
                d -= 1
                ans[i] = 3
                prev = 3
            else:
                b -= 1
                ans[i] = 1
                prev = 1
    if a<0 or b<0 or c<0 or d<0:
        ok = 0
    if ok:
        print('YES')
        print(*ans)
    else:
        print('NO')


if __name__=='__main__':
    main()