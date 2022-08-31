n = int(input())
ans = 0
cur = 0
for _ in range(n):
    x,y = map(int,input().split())
    cur -= x
    cur += y
    ans = max(ans,cur)
print(ans)