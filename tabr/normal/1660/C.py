tt = int(input())
for _ in range(tt):
    s = input()
    n = len(s)
    last = [10 ** 9] * 27
    last[26] = 0
    for i in range(n):
        c = ord(s[i]) - ord('a')
        for j in range(26):
            if j != c:
                last[j] += 1
        l26 = min(last[26] + 1, last[c])
        lc = min(last[c] + 1, last[26])
        last[c] = lc
        last[26] = l26
    print(last[26])