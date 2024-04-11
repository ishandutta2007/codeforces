mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    P = list(map(int, input().split()))

    if N == 1:
        print(0)
        exit()
    if N == 2:
        print(1)
        exit()

    odd = (N+1) // 2
    even = N // 2
    for p in P:
        if p:
            if p&1:
                odd -= 1
            else:
                even -= 1

    inf = 10000
    dp0 = [[[inf] * N for _ in range(N)] for _ in range(N)]
    dp1 = [[[inf] * N for _ in range(N)] for _ in range(N)]
    if P[0]:
        if P[0]&1:
            dp1[0][odd][even] = 0
        else:
            dp0[0][odd][even] = 0
    else:
        dp1[0][odd-1][even] = 0
        dp0[0][odd][even-1] = 0
    for i in range(1, N):
        for o in range(odd+1):
            for e in range(even+1):
                if P[i]:
                    if P[i]&1:
                        dp1[i][o][e] = min(dp1[i-1][o][e], dp0[i-1][o][e]+1)
                    else:
                        dp0[i][o][e] = min(dp1[i - 1][o][e]+1, dp0[i - 1][o][e])
                else:
                    if o:
                        dp1[i][o-1][e] = min(dp1[i-1][o][e], dp0[i-1][o][e]+1)
                    if e:
                        dp0[i][o][e-1] = min(dp1[i-1][o][e]+1, dp0[i-1][o][e])
    print(min(dp0[-1][0][0], dp1[-1][0][0]))


if __name__ == '__main__':
    main()