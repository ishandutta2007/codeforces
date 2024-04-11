mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        print((N-1)//2 + 1)


if __name__ == '__main__':
    main()