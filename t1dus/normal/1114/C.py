n,b = map(int,input().split())
if n == 1:
    print(0)
    exit()
a = []
x = b
i = 2
while i*i <= x:
    if x%i == 0:
        cnt = 0
        while x%i == 0:
            x //= i
            cnt += 1
        a.append([i,cnt])
    if i == 2:
        i += 1
    else:
        i += 2
if x > 1:
    a.append([x,1])

ans = 10**20

for i in a:
    lol = i[0]
    cur = i[0]
    cnt = 0
    while cur <= n:
        cnt += n//cur
        cur = cur*lol
    cnt //= i[1]
    ans = min(ans,cnt)
print(ans)