import sys
input = sys.stdin.buffer.readline

T = int(input())
for _ in range(T):
    N = int(input())
    p = list(map(int, input().split()))
    ok = 1

    p_upper = p[:N//2]
    border = p[N//2]
    while p_upper:
        if p_upper[-1] == border:
            p_upper.pop()
        else:
            break

    if not p_upper:
        print(0, 0, 0)
        continue

    g_score = p_upper[0]
    g = 0
    i = 0
    while True:
        if i == len(p_upper):
            print(0, 0, 0)
            ok = 0
            break
        if p_upper[i] == g_score:
            g += 1
            i += 1
        else:
            break

    if not ok:
        continue

    s = 0
    s_score = p_upper[i]
    while True:
        if i == len(p_upper):
            print(0, 0, 0)
            ok = 0
            break
        if p_upper[i] == s_score:
            s += 1
            i += 1
        else:
            if s > g:
                break
            else:
                s_score = p_upper[i]

    if not ok:
        continue

    b = len(p_upper) - g - s
    if g >= b:
        print(0, 0, 0)
    else:
        print(g, s, b)