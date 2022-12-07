from collections import deque

N = int(input())
a = list(map(int, input().split()))

adj0 = [[] for _ in range(N)]
adj1 = [[] for _ in range(N)]
que0 = deque()
que1 = deque()
for i in range(N):
    ai = a[i]
    if ai % 2 == 0:
        que0.append(i)
        if i + ai < N:
            adj0[i+ai].append(i)
        if i - ai >= 0:
            adj0[i-ai].append(i)
    else:
        que1.append(i)
        if i + ai < N:
            adj1[i + ai].append(i)
        if i - ai >= 0:
            adj1[i - ai].append(i)

ans0 = [0] * N
ans1 = [0] * N
while que1:
    v = que1.popleft()
    for u in adj0[v]:
        if ans0[u] == 0:
            ans0[u] = ans0[v] + 1
            que1.append(u)
while que0:
    v = que0.popleft()
    for u in adj1[v]:
        if ans1[u] == 0:
            ans1[u] = ans1[v] + 1
            que0.append(u)

ans = [-1] * N
for i in range(N):
    if a[i] % 2 == 0:
        if ans0[i] > 0:
            ans[i] = ans0[i]
    else:
        if ans1[i] > 0:
            ans[i] = ans1[i]

print(*ans)