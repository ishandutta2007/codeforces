s = input()
ma = eval(s)
for i in range(len(s)):
    if s[i] == '*':
        s1 = s[:i]
        s2 = s[i - len(s) + 1:]
        s3 = '(' + s1 + ')*' + s2
        ma = max(ma, eval(s3))
        s3 = s1 + '*(' + s2 + ')'
        ma = max(ma, eval(s3))
        for j in range(i):
            if s[j] == '*':
                s1 = s[:j]
                s3 = s[j + 1:i-len(s)]
                s4 = (s1 + '*(' + s3 + ')*' + s2)
                ma = max(ma, eval(s4))
print(ma)