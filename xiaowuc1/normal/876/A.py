n = int(raw_input())
a = int(raw_input()) # ro
b = int(raw_input()) # re
c = int(raw_input()) # oe
dp = [0, 1e9, 1e9] # r o e
for _ in xrange(n-1):
    next = [1e9, 1e9, 1e9]
    next[1] = min(next[1], dp[0] + a)
    next[1] = min(next[1], dp[2] + c)
    
    next[0] = min(next[0], dp[1] + a)
    next[0] = min(next[0], dp[2] + b)
    
    next[2] = min(next[2], dp[0] + b)
    next[2] = min(next[2], dp[1] + c)
    
    dp = next
print min(dp)