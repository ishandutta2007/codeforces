mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    A = list(map(int, input().split()))

    A.sort()
    ans = 0
    for i in range(N):
        ans += A[-i-1] - A[i]
    for i in range(1, N+1):
        ans = (ans * (N + i))%mod
    fac = 1
    for i in range(1, N+1):
        fac = (fac * i)%mod
    print((ans * pow(fac, mod-2, mod))%mod)


if __name__ == '__main__':
    main()