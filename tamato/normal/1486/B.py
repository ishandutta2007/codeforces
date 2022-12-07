mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        X = []
        Y = []
        N = int(input())
        for _ in range(N):
            x, y = map(int, input().split())
            X.append(x)
            Y.append(y)
        X.sort()
        Y.sort()
        if N & 1:
            print(1)
        else:
            print((X[N // 2] - X[(N // 2) - 1] + 1) * (Y[N // 2] - Y[(N // 2) - 1] + 1))


if __name__ == '__main__':
    main()