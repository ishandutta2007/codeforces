def main():
    import sys
    input = sys.stdin.readline

    N, K = map(int, input().split())
    P = list(map(int, input().split()))
    mod = 998244353

    ans1 = 0
    for i in range(K):
        ans1 += N-i

    idx = []
    for i in range(N):
        if P[i] >= N - K + 1:
            idx.append(i)
    ans2 = 1
    for i in range(K-1):
        j1 = idx[i]
        j2 = idx[i+1]
        ans2 = (ans2 * (j2-j1))%mod
    print(ans1, ans2)


if __name__ == '__main__':
    main()