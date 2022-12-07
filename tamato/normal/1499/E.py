mod = 998244353
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    S = input().rstrip('\n')
    T = input().rstrip('\n')
    NS = len(S)
    NT = len(T)
    dp_S = [[0] * (NT+1) for _ in range(NS+1)]
    dp_T = [[0] * (NT+1) for _ in range(NS+1)]
    for i in range(1, NS+1):
        dp_S[i][0] = 1
    for j in range(1, NT+1):
        dp_T[0][j] = 1
    for i in range(NS+1):
        for j in range(NT+1):
            if i == j == 0:
                continue
            elif i == 0:
                if S[0] != T[j-1]:
                    dp_S[1][j] = (dp_S[1][j] + dp_T[0][j])%mod
                if j+1 <= NT:
                    if T[j-1] != T[j]:
                        dp_T[0][j+1] = (dp_T[0][j+1] + dp_T[0][j])%mod
            elif j == 0:
                if T[0] != S[i-1]:
                    dp_T[i][1] = (dp_T[i][1] + dp_S[i][0]) % mod
                if i + 1 <= NS:
                    if S[i - 1] != S[i]:
                        dp_S[i+1][0] = (dp_S[i+1][0] + dp_S[i][0]) % mod
            else:
                if i+1 <= NS:
                    if S[i-1] != S[i]:
                        dp_S[i+1][j] = (dp_S[i+1][j] + dp_S[i][j])%mod
                    if T[j-1] != S[i]:
                        dp_S[i+1][j] = (dp_S[i+1][j] + dp_T[i][j] + dp_T[0][j])%mod
                if j+1 <= NT:
                    if T[j-1] != T[j]:
                        dp_T[i][j+1] = (dp_T[i][j+1] + dp_T[i][j])%mod
                    if S[i-1] != T[j]:
                        dp_T[i][j+1] = (dp_T[i][j+1] + dp_S[i][j] + dp_S[i][0])%mod
    ans = 0
    for i in range(1, NS+1):
        for j in range(1, NT+1):
            ans = (ans + dp_S[i][j] + dp_T[i][j])%mod
    print(ans)


if __name__ == '__main__':
    main()