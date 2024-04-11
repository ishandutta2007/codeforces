mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        a, b, c = map(int, input().split())
        if (a+b+c) % 9 != 0:
            print("NO")
        else:
            x = (a+b+c) // 9
            if min(a, b, c) >= x:
                print("YES")
            else:
                print("NO")


if __name__ == '__main__':
    main()