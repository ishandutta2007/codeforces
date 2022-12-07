def main():
    import sys
    import bisect
    input = sys.stdin.buffer.readline

    M, N, k, T = map(int, input().split())
    a = list(map(int, input().split()))
    a.append(2*10**5+1)
    a.sort(reverse=True)
    road = [[] for _ in range(N+1)]
    for _ in range(k):
        l, r, d = map(int, input().split())
        road[l].append((r, d))

    ok = 0
    ng = M+1
    mid = (ok+ng)//2
    while ng - ok > 1:
        d_min = a[mid]
        flg = 0
        rmax = 0
        t = 1
        for i in range(1, N+1):
            for r, d in road[i]:
                if d > d_min:
                    flg = 1
                    rmax = max(r, rmax)
            if i > rmax:
                flg = 0
            if flg:
                t += 3
            else:
                t += 1
        if t > T:
            ng = mid
        else:
            ok = mid
        mid = (ok+ng)//2
    print(ok)


if __name__ == '__main__':
    main()