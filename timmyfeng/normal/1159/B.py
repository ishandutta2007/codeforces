n = input()
a = map(int, raw_input().split())

ans = 10 ** 9
for i in range(n):
    ans = min(ans, a[i] / max(i, n - 1 - i))

print(ans)