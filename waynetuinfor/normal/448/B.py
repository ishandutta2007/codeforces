s = input()
t = input()

dp = [[0 for i in range(101)] for j in range(101)]

finish = False
for i in range(len(s)):
    for j in range(len(t)):
        if s[i] == t[j]:
            dp[i + 1][j + 1] = dp[i][j] + 1
        else:
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j])

if dp[len(s)][len(t)] >= len(t):
    print("automaton")
    finish = True

s = sorted(s, key=ord)
t = sorted(t, key=ord)

dp = [[0 for i in range(101)] for j in range(101)]

for i in range(len(s)):
    for j in range(len(t)):
        if s[i] == t[j]:
            dp[i + 1][j + 1] = dp[i][j] + 1
        else:
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j])


if dp[len(s)][len(t)] >= len(t) and not finish:
    if len(s) == len(t):
        print("array")
    else:
        print("both")
elif not finish:
    print("need tree")