a,b = map(int,input().split())
ans = 0
while a <= b:
    a *= 3
    b *= 2
    ans += 1
print(ans)