mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        ans = -float("inf")
        for i in range(N):
            ans = max(ans, A[i-1] - A[i])
        for i in range(1, N):
            ans = max(ans, A[i] - A[0])
        for i in range(N-1):
            ans = max(ans, A[-1] - A[i])
        print(ans)


if __name__ == '__main__':
    main()