mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        a, b, c = map(int, input().split())
        S = a+b*2+c*3
        print(S & 1)


if __name__ == '__main__':
    main()