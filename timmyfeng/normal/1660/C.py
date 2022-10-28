t = int(input())

for i in range(t):
    s = [ord(c) - ord('a') for c in input()]
    n = len(s)
    
    next = [[n] for i in range(26)]
    for i in range(n - 1, -1, -1):
        next[s[i]].append(i)
    
    dp = [0] * (n + 1)
    for i in range(n):
        next[s[i]].pop()
        if next[s[i]][-1] < n:
            dp[next[s[i]][-1] + 1] = max(dp[next[s[i]][-1] + 1], dp[i] + 2)
        dp[i + 1] = max(dp[i + 1], dp[i])
    
    print(n - dp[n])