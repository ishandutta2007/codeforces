n = int(input())
s = [input().split() for i in range(n)]

def f(i, t):
    return s[i][0][:3] if t == 0 else s[i][0][:2] + s[i][1][0]

mp = {}

for i in range(n):
    r = f(i, 0)
    if not r in mp:
        mp[r] = []
    mp[r].append(i)

used = set()
ans = [None] * n

for k, v in mp.items():
    if len(v) == 1:
        continue
    for i in v:
        r = f(i, 1)
        if r in used:
            print('NO')
            exit()
        ans[i] = r
        used.add(r)

while True:
    converged = True
    for i in range(n):
        if ans[i] is not None:
            continue
        b = [f(i, t) in used for t in range(2)]
        if b[0] and b[1]:
            print('NO')
            exit()
        elif b[0] or b[1]:
            ans[i] = f(i, 0 if b[1] else 1)
            used.add(ans[i])
            converged = False
    if converged:
        break

print('YES')
for i in range(n):
    if ans[i] is None:
        ans[i] = f(i, 0)
    print(ans[i])