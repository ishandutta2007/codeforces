mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    if N <= 2:
        print(-1)
        exit()

    ans = [[0] * N for _ in range(N)]
    for h in range(N-1):
        if h%2 == 0:
            for w in range(N):
                ans[h][w] = h * N + w
        else:
            for w in range(N):
                ans[h][N-w-1] = h * N + w

    if N%2 == 0:
        ans[N-2][N-2], ans[N-2][N-1] = ans[N-2][N-1], ans[N-2][N-2]
    else:
        ans[N - 2][N - 2], ans[N - 2][0] = ans[N - 2][0], ans[N - 2][N - 2]
    ans[N-1][N-1] = N*N - N
    for w in range(N-1):
        ans[N-1][N-w-2] = N*N-N + w
    ans[0][0] = N*N-1
    ans[N-1][N-2] = N*N
    for h in range(N):
        print(*ans[h])


if __name__ == '__main__':
    main()