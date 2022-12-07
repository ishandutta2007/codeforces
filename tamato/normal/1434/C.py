mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        a, b, c, d = map(int, input().split())
        if a > b * c:
            print(-1)
            continue

        if d > c:
            print(a)
            continue

        k = a // (b * d)
        print((a + (a - k * d * b)) * (k + 1) // 2)


if __name__ == '__main__':
    main()