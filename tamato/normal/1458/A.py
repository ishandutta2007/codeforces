mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.readline

    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    AA = []
    for i in range(N-1):
        AA.append(abs(A[i] - A[i-1]))
    g = 0
    for a in AA:
        g = gcd(g, a)
    ans = []
    for j in range(M):
        ans.append(gcd(g, A[0] + B[j]))
    print(*ans)


if __name__ == '__main__':
    main()