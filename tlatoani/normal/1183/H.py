from string import ascii_lowercase

n, k = map(int, input().split())
s = input()

todo = [1] + ([0] * n)
dp = {letter: [0] * (n + 1) for letter in ascii_lowercase}
for letter in s:
    prev = dp[letter]
    dp[letter] = [0] + todo[:n]
    todo = [a - b + c for a, b, c in zip(todo, prev, dp[letter])]

answer = 0
for cost, amt in enumerate(todo[::-1]):
    if k > amt:
        k -= amt
        answer += amt * cost
    else:
        answer += k * cost
        k = 0
        break
print(-1 if k else answer)