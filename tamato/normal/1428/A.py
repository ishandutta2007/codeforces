mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        x1, y1, x2, y2 = map(int, input().split())
        if x1 == x2 or y1 == y2:
            print(abs(x1 - x2) + abs(y1 - y2))
        else:
            print(abs(x1 - x2) + abs(y1 - y2) + 2)


if __name__ == '__main__':
    main()