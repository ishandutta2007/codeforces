mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        if N == 1 or N == 2 or N == 4:
            print(-1)
        else:
            if N % 3 == 1:
                print((N - 7) // 3, 0, 1)
            elif N % 3 == 2:
                print((N - 5) // 3, 1, 0)
            else:
                print(N // 3, 0, 0)


if __name__ == '__main__':
    main()