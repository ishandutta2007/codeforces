mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, M, a, b, c = map(int, input().split())
        P = list(map(int, input().split()))
        P.sort()
        cs = [0] * (M+1)
        for i in range(M):
            cs[i+1] = cs[i] + P[i]
        adj = [[] for _ in range(N+1)]
        for _ in range(M):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)

        v0_list = [a, b, c]
        seen_list = [[-1] * (N+1) for _ in range(3)]
        for i, v0 in enumerate(v0_list):
            seen = seen_list[i]
            que = deque()
            que.append(v0)
            seen[v0] = 0
            while que:
                v = que.popleft()
                for u in adj[v]:
                    if seen[u] == -1:
                        seen[u] = seen[v] + 1
                        que.append(u)

        ans = float("inf")
        for d in range(1, N+1):
            na = seen_list[0][d]
            nb = seen_list[1][d]
            nc = seen_list[2][d]
            if na+nb+nc > M:
                continue
            ans = min(ans, cs[nb] + cs[na+nb+nc])
        print(ans)


if __name__ == '__main__':
    main()