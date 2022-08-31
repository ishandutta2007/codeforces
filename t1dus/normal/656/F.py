s = input()
ans = 1

for i in s[1:]:
    x = int(i)
    if x == 0:
        x = 9
    ans += x
    
print(ans)