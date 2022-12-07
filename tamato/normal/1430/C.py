mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        if N == 2:
            print(2)
            print(1, 2)
            continue
        print(2)
        print(N, N-2)
        print(N-1, N-1)
        for i in range(N-3, 0, -1):
            print(i, i+2)


if __name__ == '__main__':
    main()