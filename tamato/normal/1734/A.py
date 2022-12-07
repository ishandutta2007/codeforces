mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        A.sort()
        ans = 10 ** 10
        for i in range(N - 2):
            ans = min(ans, A[i+2] - A[i])
        print(ans)


if __name__ == '__main__':
    main()