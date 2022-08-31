s = input()
n = len(s)
ind = -1
f = False
for i in range(n):
    if s[i] == '[':
        f = True
    elif s[i] == ':':
        if f:
            ind = i
            break
bind = -1
f = False
for i in range(n-1,-1,-1):
    if s[i] == ']':
        f = True
    elif s[i] == ':':
        if f:
            bind = i
            break
# print(ind,bind)
if ind == -1 or bind == -1:
    print(-1)
elif ind >= bind:
    print(-1)
else:
    ans = 4
    for i in range(ind+1,bind):
        if s[i] == '|':
            ans += 1
    print(ans)