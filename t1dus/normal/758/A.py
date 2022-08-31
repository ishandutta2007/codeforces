n = int(input())
a = list(map(int,input().split()))
x = max(a)
ans = 0
for i in a:
    ans += x-i
print(ans)