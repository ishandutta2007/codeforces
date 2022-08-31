s = input()
y = len(s)
a = []
for i in range(len(s)):
   a.append(s[i:]+s[:i])
b = []
ans = 0
for i in a:
    if i not in b:
        b.append(i)
        ans += 1
print(ans)