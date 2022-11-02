n, k = map(int, input().split())
res = ""
for i in range(n):
    res += chr((i%k)+97)
print(res)