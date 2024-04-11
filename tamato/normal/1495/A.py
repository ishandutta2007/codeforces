mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import hypot
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        X = []
        Y = []
        for _ in range(N*2):
            x, y = map(int, input().split())
            if x == 0:
                Y.append(abs(y))
            else:
                X.append(abs(x))
        X.sort()
        Y.sort()
        ans = 0
        for x, y in zip(X, Y):
            ans += hypot(x, y)
        print(ans)


if __name__ == '__main__':
    main()