s = [ord(x) - ord('A') for x in input()]
ok = True
for i in range(2, len(s)):
    if s[i] != (s[i - 2] + s[i - 1]) % 26:
        ok = False
print('YES' if ok else 'NO')