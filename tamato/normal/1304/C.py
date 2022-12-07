def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, M = map(int, input().split())
        Tmax = Tmin = M
        t_prev = 0
        ok = 1
        for _ in range(N):
            t, l, h = map(int, input().split())
            Tmin -= t - t_prev
            Tmax += t - t_prev
            if l > Tmax or h < Tmin:
                ok = 0
            Tmin = max(l, Tmin)
            Tmax = min(h, Tmax)
            t_prev = t
        if ok:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()