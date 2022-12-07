mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    NMAX = 2 * 10 ** 4 + 1
    is_prime = [1] * (NMAX + 1)
    is_prime[0] = is_prime[1] = 0
    for p in range(2, NMAX + 1):
        if not is_prime[p]:
            continue
        for d in range(2, NMAX + 1):
            if p * d > NMAX:
                break
            is_prime[p * d] = 0

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        S = sum(A)
        if is_prime[S]:
            T = set(range(1, N+1))
            for i in range(N):
                if A[i] & 1:
                    T.discard(i+1)
                    break
            print(N-1)
            print(*list(T))
        else:
            print(N)
            print(*list(range(1, N+1)))


if __name__ == '__main__':
    main()