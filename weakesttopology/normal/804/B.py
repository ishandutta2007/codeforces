s = input()
mod = 10 ** 9 + 7

s = s[::-1]

ans = 0
bs = 0
for x in s[s.index('b'):]:
    if x == 'b':
        bs += 1
    else:
        ans += bs
        ans %= mod
        bs = 2 * bs % mod
print(ans)