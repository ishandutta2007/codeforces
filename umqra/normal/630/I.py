n = int(input())
ans = 2 * 4 * 3 * 4**(n - 3)
if n > 3:
    ans += (n - 3) * 3 * 3 * 4**(n - 4) * 4
print(ans)