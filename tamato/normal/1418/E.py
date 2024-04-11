mod = 998244353
eps = 10**-9


def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.buffer.readline

    N, M = map(int, input().split())
    D = list(map(int, input().split()))
    D.sort()

    cs = [0] * (N+1)
    for i in range(N):
        cs[i+1] = (cs[i] + D[i])%mod
    ans = [0] * M
    for m in range(M):
        a, b = map(int, input().split())
        i = bisect_left(D, b)
        if i == N:
            ans[m] = 0
            continue
        k = N - i
        if a > k:
            ans[m] = 0
            continue
        ans[m] = (((cs[-1] - cs[i])%mod * ((k-a) * pow(k, mod-2, mod))%mod)%mod
                  + ((cs[i] * (k+1-a))%mod * pow(k+1, mod-2, mod))%mod)%mod
    print(*ans, sep="\n")


if __name__ == '__main__':
    main()