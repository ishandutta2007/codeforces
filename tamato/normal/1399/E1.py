mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    from heapq import heappop, heappush
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, S = map(int, input().split())
        adj = [[] for _ in range(N+1)]
        for _ in range(N-1):
            a, b, c = map(int, input().split())
            adj[a].append((b, c))
            adj[b].append((a, c))
        que = deque()
        que.append(1)
        seen = [-1] * (N+1)
        seen[1] = 0
        par = [0] * (N+1)
        child = [[] for _ in range(N+1)]
        seq = []
        C = [0] * (N+1)
        while que:
            v = que.popleft()
            seq.append(v)
            for u, c in adj[v]:
                if seen[u] == -1:
                    seen[u] = seen[v] + 1
                    par[u] = v
                    child[v].append(u)
                    que.append(u)
                    C[u] = c
        seq.reverse()
        dp = [0] * (N+1)
        pq = []
        T = 0
        for v in seq:
            if not child[v]:
                dp[v] = 1
            else:
                for u in child[v]:
                    dp[v] += dp[u]
            heappush(pq, -((((C[v] + 1)//2 * dp[v]) << 21) + v))
            T += C[v] * dp[v]

        ans = 0
        while T > S:
            x = heappop(pq)
            v = (-x) & ((1<<21)-1)
            T -= (C[v] + 1)//2 * dp[v]
            C[v] //= 2
            if C[v]:
                heappush(pq, -((((C[v] + 1)//2 * dp[v]) << 21) + v))
            ans += 1
        print(ans)


if __name__ == '__main__':
    main()