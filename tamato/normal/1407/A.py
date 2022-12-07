mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import Counter
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        if N == 2:
            if A[0] == A[1] == 1:
                print(2)
                print(1, 1)
            else:
                print(1)
                print(0)
            continue

        C = Counter(A)
        if (N//2)%2 == 0:
            if C[0] >= C[1]:
                a = 0
            else:
                a = 1
            print(N//2)
            print(*[a] * (N//2))
        else:
            n = N // 2
            if C[0] >= n+1:
                print(n + 1)
                print(*[0] * (n + 1))
            elif C[1] >= n+1:
                print(n + 1)
                print(*[1] * (n + 1))
            else:
                print(n)
                print(*[0] * n)


if __name__ == '__main__':
    main()