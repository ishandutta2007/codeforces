def main():
    import sys
    import bisect
    input = sys.stdin.readline

    N = int(input())
    smin = []
    smax = []
    ok = 0
    for i in range(N):
        l_si = list(map(int, input().split()))
        l = l_si[0]
        si = l_si[1:]
        flg = 0
        prev = 10**9
        for a in si:
            if a > prev:
                flg = 1
                break
            prev = a
        if flg:
            ok += 1
        else:
            smin.append(min(si))
            smax.append(max(si))
    smax.sort()
    ans = ok * N
    for i in smin:
        ans += N - bisect.bisect_left(smax, i+1)
    print(ans)


if __name__ == '__main__':
    main()