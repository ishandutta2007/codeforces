a,b = map(int,input().split())
ans = 0
while a > 0:
        ans += 1
        a -= 1
        if ans % b == 0:
            a += 1
print(ans)