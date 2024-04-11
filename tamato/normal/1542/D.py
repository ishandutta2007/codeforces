mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    Q = []
    for i in range(N):
        S = input().rstrip('\n')
        if S[0] == "+":
            _, t = S.split()
            Q.append(int(t) + 0.00001 * i)
        else:
            Q.append(-1)
    ans = 0
    for i0 in range(N):
        a = Q[i0]
        if a == -1:
            continue
        dp = [1]
        for i in range(N):
            dp_new = [0] * (i+2)
            if i != i0:
                if Q[i] == -1:
                    for j in range(i+1):
                        dp_new[j] = dp[j]
                        if j:
                            dp_new[j-1] = (dp_new[j-1] + dp[j])%mod
                        else:
                            if i < i0:
                                dp_new[j] = (dp_new[j] + dp[j])%mod
                else:
                    if Q[i] < a:
                        for j in range(i+1):
                            dp_new[j] = (dp_new[j] + dp[j])%mod
                            dp_new[j+1] = dp[j]
                    else:
                        for j in range(i+1):
                            dp_new[j] = (dp[j] * 2)%mod
            else:
                for j in range(i+1):
                    dp_new[j] = dp[j]
            dp = dp_new
        a = int(a + 0.3)
        for j in range(N):
            ans = (ans + (a * dp[j])%mod)%mod
    print(ans)


if __name__ == '__main__':
    main()