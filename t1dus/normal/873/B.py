'''input
8
11010111
'''
n = int(input())
s = input()
a = [0]
d = {0:0}
for i in range(n):
    if s[i] == '1': a.append(a[-1]+1)
    else: a.append(a[-1]-1)
    if a[i+1] not in d: d[a[i+1]] = i+1
ans = 0
for i in range(1,n+1):
    ans = max(ans,i-d[a[i]])
print(ans)