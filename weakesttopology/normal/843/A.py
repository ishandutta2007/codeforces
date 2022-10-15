n = int(input())
a = list(map(int, input().split()))

b = a.copy()
b.sort()

pos = {x: i for i, x in enumerate(b)}

vis = [False] * n
subs = []
for x in a:
    if vis[pos[x]]:
        continue
    I = []
    while not vis[pos[x]]:
        I.append(pos[x] + 1)
        vis[pos[x]] = True
        x = a[pos[x]]
    subs.append(I)

print(len(subs))
for I in subs:
    print(len(I), *I)