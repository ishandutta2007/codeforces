mod = 998244353
eps = 10**-9


def main():
    import sys
    from bisect import bisect_left
    input = sys.stdin.readline

    N, M = map(int, input().split())
    A = [[0] * N for _ in range(M)]
    for i in range(N):
        line = list(map(int, input().split()))
        for j in range(M):
            A[j][i] = line[j]
    F = 1
    for i in range(1, N+1):
        F = (F * i)%mod
    invF = pow(F, mod-2, mod)
    ans = 0
    for B in A:
        B.sort()
        tmp = 1
        for i in range(N, 0, -1):
            j = bisect_left(B, i+1)
            k = max(0, N - j - (N - i))
            tmp = (tmp * k)%mod
        ans = (ans + (F - tmp))%mod
    print((ans * invF)%mod)


if __name__ == '__main__':
    main()