def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        S = input().rstrip('\n')

        cnt = [[0] * K for _ in range(26)]
        for i, s in enumerate(S):
            j = ord(s) - 97
            cnt[j][i%K] += 1
        ans = 0
        L = (N//K) * 2
        for i in range(K//2):
            tmp = N+1
            for j in range(26):
                tmp = min(tmp, L - (cnt[j][i] + cnt[j][K-i-1]))
            ans += tmp
        if K&1:
            tmp = N+1
            for j in range(26):
                tmp = min(tmp, N//K - cnt[j][K//2])
            ans += tmp
        print(ans)


if __name__ == '__main__':
    main()