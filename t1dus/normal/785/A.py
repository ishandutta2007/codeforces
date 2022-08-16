n = int(input())

ans = 0
for i in range(n):
    s = input().lower()[0]
    if s == 't':
        ans += 4
    elif s == 'c':
        ans += 6
    elif s == 'o':
        ans += 8
    elif s == 'd':
        ans += 12
    else:
        ans += 20
        
print(ans)