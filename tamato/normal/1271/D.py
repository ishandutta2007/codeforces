import sys
input = sys.stdin.buffer.readline

N, M, K = map(int, input().split())
A = [0] * N
B = [0] * N
C_raw = [0] * N
for i in range(N):
    A[i], B[i], C_raw[i] = map(int, input().split())
adj = [[] for _ in range(N+1)]
for _ in range(M):
    u, v = map(int, input().split())
    adj[v].append(u)


C = [[] for _ in range(N)]
for i in range(N):
    if adj[i+1]:
        C[max(adj[i+1])-1].append(C_raw[i])
    else:
        C[i].append(C_raw[i])
for i in range(N):
    if C[i]:
        C[i].sort(reverse=True)

dp = [[-10**5] * 5001 for _ in range(N+1)]
dp[0][K] = 0
for i in range(N):
    for k in range(5001):
        if dp[i][k] >= 0:
            if k >= A[i]:
                dp[i+1][k+B[i]] = max(dp[i+1][k+B[i]], dp[i][k])
                p = k + B[i]
                q = 0
                cnt = 0
                for ci in C[i]:
                    if p > 0:
                        p -= 1
                        q += ci
                        cnt += 1
                        dp[i+1][k+B[i] - cnt] = max(dp[i+1][k+B[i] - cnt], dp[i][k] + q)
                    else:
                        break

if max(dp[-1]) >= 0:
    print(max(dp[-1]))
else:
    print(-1)