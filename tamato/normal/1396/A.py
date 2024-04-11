mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    if N == 1:
        print(1, 1)
        print(-A[0])
        print(1, 1)
        print(0)
        print(1, 1)
        print(0)
        exit()

    print(1, N-1)
    L = []
    for a in A[:-1]:
        L.append((N-1) * a)
    print(*L)
    print(N, N)
    print((N-1) * A[-1])
    print(1, N)
    L = []
    for a in A:
        L.append((-N) * a)
    print(*L)


if __name__ == '__main__':
    main()