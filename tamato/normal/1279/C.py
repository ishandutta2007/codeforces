import sys
input = sys.stdin.buffer.readline

t = int(input())
for _ in range(t):
    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    idx_A = {}
    for i in range(N):
        idx_A[A[i]] = i+1
    ans = 0
    j = 0
    for i, b in enumerate(B):
        if idx_A[b] > j:
            j = idx_A[b]
            ans += 2*j-1 - i*2
        else:
            ans += 1
    print(ans)