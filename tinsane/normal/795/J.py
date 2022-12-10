class Solver:
    def __init__(self):
        pass

    def solve(self):
        n, k = map(int, input().split())
        s = input()
        dp = [[[False for _ in range(n+1)] for _ in range(n+1)] for _ in range(n+1)]
        dp[0][0][0] = True
        for pos in range(n):
            for streak in range(n+1):
                for mx in range(n+1):
                    if not dp[pos][streak][mx]:
                        continue
                    #print(pos, streak, mx)
                    if s[pos] == 'N' or s[pos] == '?':
                        dp[pos+1][streak+1][max(mx, streak+1)] = True
                    if s[pos] == 'Y' or s[pos] == '?':
                        dp[pos+1][0][mx] = True
        for streak in range(n+1):
            if dp[n][streak][k]:
                print('YES')
                return
        print('NO')


if __name__ == '__main__':
    s = Solver()
    s.solve()