mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    debug = 0

    def ask(A):
        if debug:
            aa = 0
            d = 10000
            for a in A:
                if ds[a] + dt[a] < d:
                    d = ds[a] + dt[a]
                    aa = a
            return aa, d
        else:
            query = ["?", len(A)]
            query.extend(A)
            print(*query)
            sys.stdout.flush()
            a, d = map(int, input().split())
            if a == d == -1:
                exit()
            return a, d

    for _ in range(int(input())):
        N = int(input())
        adj = [[] for _ in range(N+1)]
        for _ in range(N-1):
            a, b = map(int, input().split())
            adj[a].append(b)
            adj[b].append(a)
        if debug:
            s, t = map(int, input().split())
            ds = [-1] * (N+1)
            que = deque()
            que.append(s)
            ds[s] = 0
            while que:
                v = que.popleft()
                for u in adj[v]:
                    if ds[u] == -1:
                        que.append(u)
                        ds[u] = ds[v] + 1
            dt = [-1] * (N + 1)
            que.append(t)
            dt[t] = 0
            while que:
                v = que.popleft()
                for u in adj[v]:
                    if dt[u] == -1:
                        que.append(u)
                        dt[u] = dt[v] + 1
        v0, d = ask(list(range(1, N+1)))
        que = deque()
        que.append(v0)
        dist = [-1] * (N+1)
        dist[v0] = 0
        par = [0] * (N+1)
        while que:
            v = que.popleft()
            for u in adj[v]:
                if dist[u] == -1:
                    dist[u] = dist[v]+1
                    que.append(u)
                    par[u] = v
        dist_list = [[] for _ in range(N + 1)]
        for v in range(1, N+1):
            dist_list[dist[v]].append(v)
        v1 = v0
        seen = [0] * (N+1)
        seen[v0] = 1
        while d:
            dd = (d+1) // 2
            A = []
            for u in dist_list[dist[v0] + dd]:
                if not seen[u]:
                    A.append(u)
            if v0 != v1:
                for u in dist_list[dist[v1] + dd]:
                    if not seen[u]:
                        A.append(u)
            a, _ = ask(A)
            aa = a
            for _ in range(dd):
                seen[aa] = 1
                aa = par[aa]
            if aa == v0:
                v0 = a
            else:
                v1 = a
            d -= dd
        print(*["!", v0, v1])
        sys.stdout.flush()
        verdict = input().rstrip('\n')
        if verdict == "Incorrect":
            exit()


if __name__ == '__main__':
    main()