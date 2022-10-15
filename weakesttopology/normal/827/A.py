import sys
input = sys.stdin.readline

n = int(input())
L = 0

t, x = [], []
for i in range(n):
    v = input().split()
    t.append(v[0])
    pos = list(map(lambda x: int(x) - 1, v[2:]))
    x.append(pos)
    L = max(L, pos[-1] + len(t[i]))

nxt = list(range(L + 1))
ans = ['a'] * L

def find(j):
    jcopy = j
    while nxt[j] != j:
        j = nxt[j]
    j, jcopy = jcopy, j
    while nxt[j] != j:
        tmp = nxt[j]
        nxt[j] = jcopy
        j = tmp
    return j

for i in range(n):
    for j in x[i]:
        l = j
        j = find(nxt[j])
        while j < l + len(t[i]):
            ans[j] = t[i][j - l]
            nxt[j] = j + 1
            j = find(nxt[j])

print(*ans, sep='')