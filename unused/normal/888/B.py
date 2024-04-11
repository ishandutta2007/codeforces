ans = 0
cnt = [0] * 4
s = 'ULDR'
raw_input()
for ch in raw_input():
    p = s.find(ch)
    if cnt[(p + 2) % 4]:
        cnt[(p + 2) % 4] -= 1
        ans += 2
    else:
        cnt[p] += 1
print ans