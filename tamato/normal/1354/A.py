mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        a, b, c, d = map(int, input().split())

        if a <= b:
            print(b)
        else:
            rest = a - b
            if c <= d:
                print(-1)
            else:
                k = (rest - 1) // (c-d) + 1
                print(b + c * k)


if __name__ == '__main__':
    main()