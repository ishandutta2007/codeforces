mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        A = list(map(int, input().split()))

        for i, a in enumerate(A[:-1]):
            if a <= K:
                A[i] = 0
                A[-1] += a
                K -= a
            else:
                A[i] -= K
                A[-1] += K
                break
        print(*A)


if __name__ == '__main__':
    main()