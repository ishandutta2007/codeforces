n = int(input())
p = list(map(lambda x: int(x) - 1, input().split()))

vis = [False] * n
odd = 0
for x in range(n):
    if vis[x]:
        continue
    odd ^= 1
    while not vis[x]:
        odd ^= 1
        vis[x] = True
        x = p[x]

print('Petr' if (n + odd) % 2 == 0 else 'Um_nik')