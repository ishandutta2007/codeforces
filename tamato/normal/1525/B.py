mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        P = list(map(int, input().split()))

        if P == list(range(1, N+1)):
            print(0)
        elif P[0] == 1 or P[-1] == N:
            print(1)
        elif P[0] == N and P[-1] == 1:
            print(3)
        else:
            print(2)


if __name__ == '__main__':
    main()