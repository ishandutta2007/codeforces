n, k = map(int, raw_input().split())
s = [ord(x) - ord('0') for x in raw_input()]

cur = 0
while cur < len(s) and k > 0:
    if cur == 0 and len(s) > 1:
        if s[cur] > 1:
            s[cur] = 1
            k -= 1
    else:
        if s[cur] > 0:
            s[cur] = 0
            k -= 1
    cur += 1

print(''.join(str(x) for x in s))