s = input()
s1 = input()
d = {}
f = True
for i in range(len(s)):
    
    if s[i] in d:
        if d[s[i]] != s1[i]:
            print(-1)
            f = False
            break
    if s1[i] in d:
        if d[s1[i]] != s[i]:
            print(-1)
            f = False
            break
    d[s[i]] = s1[i]
    d[s1[i]] = s[i]
if f:
    ans = 0
    d1 = {}
    marked = {}
    for i in 'abcdefghijklmnopqrstuvwxyz':
        marked[i] = False
    for i in d:
        if not marked[i] and i != d[i]:
            marked[i] = True
            marked[d[i]] = True
            ans += 1
            d1[i] = d[i]
    print(ans)
    for i in d1:
        print(i,d1[i])