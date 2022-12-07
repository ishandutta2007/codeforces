mod = 998244353


def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, M = map(int, input().split())
        adj = [[] for _ in range(N + 1)]
        E = []
        for i in range(M):
            a, b = map(int, input().split())
            adj[a].append((b, i))
            adj[b].append((a, i))
            E.append((a, b))

        que = deque()
        que.append(1)
        seen = [-1] * (N+1)
        seen[1] = 0
        par = [0] * (N+1)
        ans = [0] * M
        unused = set()
        unused_i = []
        while que:
            v = que.popleft()
            for u, i in adj[v]:
                if seen[u] == -1:
                    seen[u] = seen[v] + 1
                    par[u] = v
                    que.append(u)
                    ans[i] = 1
                else:
                    if par[v] != u:
                        unused.add(u)
                        unused.add(v)
                        unused_i.append(i)

        if M == N + 2 and len(unused) == 3:
            i = unused_i[0]
            u, v = E[i]
            if seen[u] > seen[v]:
                u, v = v, u
            for vv, j in adj[u]:
                if vv == v:
                    ans[j] = 1
            for uu, j in adj[v]:
                if uu == u:
                    ans[j] = 1
            p = par[v]
            for pp, j in adj[v]:
                if pp == p:
                    ans[j] = 0
            for vv, j in adj[p]:
                if vv == v:
                    ans[j] = 0
        print("".join(map(str, ans)))


if __name__ == '__main__':
    main()