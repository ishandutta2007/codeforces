def main():
    import sys
    input = sys.stdin.buffer.readline

    mod = 998244353
    N, K, M = map(int, input().split())
    cond = []
    for _ in range(M):
       cond.append(tuple(map(int, input().split())))

    ans = 1
    for k in range(K):
        one = [0] * (N+1)
        zero_cond = [0] * (N+1)
        for l, r, x in cond:
            if x >> k & 1:
                one[l-1] += 1
                one[r] -= 1
            else:
                zero_cond[r] = max(zero_cond[r], l)
        for i in range(N):
            one[i+1] += one[i]
        dp = [0] * (N+1)
        dp[0] = 1
        cs = [0] * (N+2)
        cs[1] = 1
        R = 0
        for i in range(N):
            if not one[i]:
                dp[i+1] = (cs[i+1] - cs[R])%mod
            cs[i+2] = (cs[i+1] + dp[i+1])%mod
            R = max(R, zero_cond[i+1])
        ans = (ans * (cs[-1] - cs[R])%mod)%mod
    print(ans)


if __name__ == '__main__':
    main()