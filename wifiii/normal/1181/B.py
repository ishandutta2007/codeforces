l = int(input())
s = input()
ans = -1
mid = l // 2
for i in range(mid+1,l):
    s1 = s[:i]
    s2 = s[i:]
    if s1[0]=='0':
        continue
    if s2[0]=='0':
        continue
    if ans==-1:
        ans = int(s1) + int(s2)
    else:
        ans = min(ans, int(s1)+int(s2))
    break
for i in range(mid,0,-1):
    s1 = s[:i]
    s2 = s[i:]
    if s1[0]=='0':
        continue
    if s2[0]=='0':
        continue
    if ans==-1:
        ans = int(s1) + int(s2)
    else:
        ans = min(ans, int(s1)+int(s2))
    break
for i in range(mid-1,0,-1):
    s1 = s[:i]
    s2 = s[i:]
    if s1[0]=='0':
        continue
    if s2[0]=='0':
        continue
    if ans==-1:
        ans = int(s1) + int(s2)
    else:
        ans = min(ans, int(s1)+int(s2))
    break
print(ans)