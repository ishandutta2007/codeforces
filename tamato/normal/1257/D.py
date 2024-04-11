def main():
    import sys
    from operator import itemgetter
    import bisect
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().split()))
        M = int(input())
        info = []
        for _ in range(M):
            p, s = map(int, input().split())
            info.append((p, s))

        info.sort(key=itemgetter(0), reverse=True)
        info.sort(key=itemgetter(1), reverse=True)
        P = []
        S = []
        pmax = 0
        for p, s in info:
            if p > pmax:
                P.append(p)
                S.append(s)
                pmax = p
        lenP = len(P)

        d = 0
        ans = 0
        while True:
            i = bisect.bisect_left(P, A[d])
            if i == lenP:
                ans = -1
                break
            ans += 1
            cnt = 0
            while cnt < S[i]:
                if P[i] >= A[d]:
                    d += 1
                    cnt += 1
                    if d == N:
                        break
                else:
                    i += 1
                    if i == lenP:
                        break
            if d == N:
                break
        print(ans)


if __name__ == '__main__':
    main()