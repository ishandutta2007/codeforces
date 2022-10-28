input()
s = raw_input()

ans = 0
for c in s:
    if c == '-':
        ans = max(0, ans - 1)
    else:
        ans += 1

print(ans)