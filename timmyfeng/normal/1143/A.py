n = input()
a = map(int, raw_input().split())

ans = n - 1
while a[ans - 1] == a[ans]:
    ans -= 1
print(ans)