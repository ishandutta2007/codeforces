mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())

        ok = 1
        ng = N
        mid = (ok+ng) // 2
        while ng - ok > 1:
            if ((mid*mid) + 1) // 2 <= N:
                ok = mid
            else:
                ng = mid
            mid = (ok+ng) // 2
        if ok < 3:
            print(0)
        else:
            print((ok+1) // 2 - 1)


if __name__ == '__main__':
    main()