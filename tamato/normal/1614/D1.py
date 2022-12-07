mod = 1000000007
eps = 10**-9
M = 5 * 10 ** 6


def main():
    import sys
    from collections import Counter
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))

    C = Counter(A)
    cnt = [0] * (M+1)
    for g in range(1, M+1):
        for x in range(1, M+1):
            if g * x > M:
                break
            if g * x in C:
                cnt[g] += C[g*x]

    dp = [0] * (M+1)
    for i in range(M, 0, -1):
        dp[i] = i * cnt[i]
        for x in range(2, M+1):
            if i * x > M:
                break
            dp[i] = max(dp[i], dp[i * x] + i * (cnt[i] - cnt[i * x]))
    print(max(dp))


if __name__ == '__main__':
    main()