import sys
input = sys.stdin.buffer.readline

t = int(input())
for _ in range(t):
    N, s = map(int, input().split())
    A = list(map(int, input().split()))
    cs = [0] * (N+1)
    cm = [0] * (N+1)
    cm_idx = [0] * (N+1)
    for i in range(N):
        cs[i+1] = cs[i] + A[i]
        if cm[i] < A[i]:
            cm[i+1] = A[i]
            cm_idx[i+1] = i+1
        else:
            cm[i + 1] = cm[i]
            cm_idx[i + 1] = cm_idx[i]
    if cs[-1] <= s:
        print(0)
        continue
    opt = [0] * (N+1)
    for i in range(1, N+1):
        opt[i] = cs[i] - cm[i]
    for i in range(1, N+1):
        if opt[i] > s:
            print(cm_idx[i-1])
            break
        if i == N:
            print(cm_idx[i])