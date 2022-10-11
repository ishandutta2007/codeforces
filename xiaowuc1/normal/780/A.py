n = int(raw_input())
l = raw_input().split()
s = dict()
ret = 0
for x in l:
    if x in s:
        del s[x]
    else:
        s[x] = True
        ret = max(ret, len(s))
print ret