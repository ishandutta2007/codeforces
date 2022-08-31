def f(c):
    if c == 'r':
        return 1
    elif c == 'b':
        return 2
    elif c == 'y':
        return 3
    elif c == 'g':
        return 4
    return 0
a = [0,0,0,0,0]
ans = [0,0,0,0,0]
s = list(input().lower())
n = len(s)
for i in range(n):
    if s[i] != "!":
        a[i%4] = f(s[i])
        
for i in range(n):
    if s[i] == "!":
        ans[a[i%4]] += 1
print(ans[1],ans[2],ans[3],ans[4])