mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N, K = map(int, input().split())
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)

    from collections import deque
    que = deque()
    que.append(1)
    seen = [-1] * (N+1)
    seen[1] = 0
    par = [0] * (N+1)
    child = [[] for _ in range(N+1)]
    seq = []
    while que:
        v = que.popleft()
        seq.append(v)
        for u in adj[v]:
            if seen[u] == -1:
                seen[u] = seen[v] + 1
                par[u] = v
                child[v].append(u)
                que.append(u)
    seq.reverse()

    dp = [1] * (N+1)
    for v in seq:
        for u in child[v]:
            dp[v] += dp[u]
    A = []
    for v in range(1, N+1):
        A.append(seen[v] - (dp[v]-1))
    A.sort(reverse=True)
    ans = 0
    for i in range(K):
        ans += A[i]
    print(ans)
    #print(A)


if __name__ == '__main__':
    main()