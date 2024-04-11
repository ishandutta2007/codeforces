mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        x = A.count(1)
        y = A.count(0)
        print(x * pow(2, y))


if __name__ == '__main__':
    main()