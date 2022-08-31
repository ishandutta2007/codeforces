ans = 0
for _ in range(int(input())):
    ans += sum(list(map(int,input().split())))//2
print(ans)