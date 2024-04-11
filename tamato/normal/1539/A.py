mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        n, x, t = map(int, input().split())
        y = min(t // x, n-1)
        print(y * (n - y) + y * (y-1) // 2)


if __name__ == '__main__':
    main()