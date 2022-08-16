n = int(input())
a = list(map(int,input().split()))
a.sort()
ans = 0
for i in a:
    if a[0] < i and a[-1] > i:
        ans += 1
print(ans)