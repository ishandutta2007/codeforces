mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def f(x, p):
        return x * ((p-1) // x + 1) - p

    for _ in range(int(input())):
        p, a, b, c = map(int, input().split())
        print(min(f(a, p), f(b, p), f(c, p)))


if __name__ == '__main__':
    main()