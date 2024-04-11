mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N, M, K = map(int, input().split())
    A = list(map(int, input().split()))

    cs = [0] * (N+1)
    mi = [10**10] * M
    mi[0] = 0
    ans = 0
    for i, a in enumerate(A):
        cs[i+1] = cs[i] + (a - K / M)
        mi[(i+1)%M] = min(mi[(i+1)%M], cs[i+1])
        for j in range(M):
            ans = max(ans, cs[i+1] - mi[(i + 1 + j)%M] - (K / M) * j)
    print(max(int(ans + 0.5), 0))


if __name__ == '__main__':
    main()