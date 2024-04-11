mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N = int(input())
        adj = [[] for _ in range(N+1)]
        for _ in range(N-1):
            a, b = map(int, input().split())
            adj[a].append(b)
            adj[b].append(a)

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

        size = [1] * (N+1)
        a = -1
        b = -1
        for v in seq:
            for u in child[v]:
                size[v] += size[u]
                if size[u] == N // 2 and N%2 == 0:
                    a = v
                    b = u
        if a == b == -1:
            a = seq[0]
            b = par[a]
            print(a, b)
            print(a, b)
        else:
            while child[b]:
                b = child[b][0]
            print(b, par[b])
            print(a, b)


if __name__ == '__main__':
    main()