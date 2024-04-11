mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        idx = [[-1] for _ in range(N+1)]
        for i, a in enumerate(A):
            idx[a].append(i)
        for i in range(N+1):
            idx[i].append(N)
        ans = [N+1] * (N+1)
        for i in range(1, N+1):
            d = 0
            for j in range(len(idx[i]) - 1):
                d = max(d, idx[i][j+1] - idx[i][j])
            if d != N+1:
                ans[d] = min(ans[d], i)
        mi = N+1
        for i in range(1, N+1):
            if mi < ans[i]:
                ans[i] = mi
            mi = min(mi, ans[i])
            if ans[i] == N+1:
                ans[i] = -1
        print(*ans[1:])


if __name__ == '__main__':
    main()