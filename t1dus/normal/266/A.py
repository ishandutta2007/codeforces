n = int(input())
s = list(input())
i = 1
ans = 0
while i < n:
    if s[i] == s[i-1]:
        n -= 1
        ans += 1
        del s[i]
    else:
        i += 1
print(ans)