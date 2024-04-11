mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, r = map(int, input().split())
        if r >= N:
            print(N * (N-1) // 2 + 1)
        else:
            print(r * (r+1) // 2)


if __name__ == '__main__':
    main()