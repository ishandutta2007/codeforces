n,k = map(int,input().split())
cur = sum(list(map(int,input().split())))
ans = 0
while round((cur/n)+0.00000000001) < k:
    cur += k
    n += 1
    ans += 1
print(ans)