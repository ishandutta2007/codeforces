mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, M = map(int, input().split())
        LRX = []
        for _ in range(M):
            LRX.append(tuple(map(int, input().split())))

        ans = 0
        P = pow(2, N-1, mod)
        for lv in range(30):
            imos = [0] * (N+1)
            for l, r, x in LRX:
                if x >> lv & 1 == 0:
                    imos[l-1] += 1
                    imos[r] -= 1
            cnt = [0] * N
            zero = 0
            one = 0
            for i in range(N):
                cnt[i] = cnt[i-1] + imos[i]
                if cnt[i]:
                    zero += 1
                else:
                    one += 1
            if one:
                ans = (ans + (pow(2, lv, mod) * P)%mod)%mod
        print(ans)


if __name__ == '__main__':
    main()