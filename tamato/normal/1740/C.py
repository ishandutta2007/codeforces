mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        A.sort()
        S = set(A)
        if len(S) == 1:
            print(0)
        elif len(S) == 2:
            print((A[-1] - A[0]) * 2)
        else:
            ans = 0
            for i in range(N - 2):
                ans = max(ans, A[-1] - A[i] + A[i+1] - A[i])
            for i in range(2, N):
                ans = max(ans, A[i] - A[0] + A[i] - A[i-1])
            print(ans)


if __name__ == '__main__':
    main()