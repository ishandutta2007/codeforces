mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def ask(t, i, j, k):
        print(t, i, j, k)
        sys.stdout.flush()
        return int(input())

    """
    def ask(t, i, j, k):
        xi, yi = XY[i-1]
        xj, yj = XY[j-1]
        xk, yk = XY[k-1]
        if t == 1:
            return abs((xj-xi) * (yk-yi) - (xk-xi) * (yj-yi))
        else:
            if (xj-xi) * (yk-yi) - (xk-xi) * (yj-yi) > 0:
                return 1
            else:
                return -1
    """

    N = int(input())
    """
    XY = []
    for _ in range(N):
        XY.append(tuple(map(int, input().split())))
    """

    p1 = 1
    p2 = 2
    for k in range(3, N+1):
        flg = ask(2, 1, p2, k)
        if flg == -1:
            p2 = k
    SK = []
    for k in range(2, N+1):
        if k == p2:
            continue
        S = ask(1, 1, p2, k)
        SK.append((S, k))
    SK.sort(key=lambda x: x[0])
    pmax = SK[-1][1]
    p_first = []
    p_second = []
    for S, k in SK[:-1]:
        flg = ask(2, 1, pmax, k)
        if flg == -1:
            p_first.append((S, k))
        else:
            p_second.append((S, k))
    p_first.sort(key=lambda x: x[0])
    p_second.sort(key=lambda x: x[0], reverse=True)
    ans = [0, 1, p2]
    for _, p in p_first:
        ans.append(p)
    ans.append(pmax)
    for _, p in p_second:
        ans.append(p)
    print(*ans)
    sys.stdout.flush()
    #print(p2, pmax, p_first, p_second)


if __name__ == '__main__':
    main()