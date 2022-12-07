mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    g = A[0]
    for a in A[1:]:
        g = gcd(g, a)
    B = [a // g for a in A]
    S = sum(B)
    if S & 1:
        print(0)
        exit()
    dp = [[0] * (S + 1) for _ in range(N+1)]
    dp[0][0] = 1
    for i in range(N):
        b = B[i]
        for j in range(S+1):
            if dp[i][j]:
                dp[i+1][j] = 1
                if j + b <= S:
                    dp[i+1][j+b] = 1
    if dp[-1][S // 2] == 0:
        print(0)
    else:
        print(1)
        for i in range(N):
            if B[i] & 1:
                print(i+1)
                break


if __name__ == '__main__':
    main()