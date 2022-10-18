s = raw_input()

n = len(s)

vowel_set = {'I', 'E', 'A', 'O', 'U', 'Y'}

pre = [0] * (n + 1)
for i in range(len(s)):
    pre[i + 1] = pre[i] + (s[i] in vowel_set)

res = pre[n]
lastv = 0
for l in range(2, n + 1):
    curv = lastv + pre[l - 1] + (pre[n] - pre[n - l + 1])
    res += float(pre[n] * l - curv) / l
    lastv = curv

print '%.8f' % res