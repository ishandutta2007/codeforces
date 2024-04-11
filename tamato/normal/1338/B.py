mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
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

    ok = 1
    flg = -1
    is_leaf = [0] * (N+1)
    for v in range(1, N+1):
        if len(adj[v]) == 1:
            if flg == -1:
                flg = seen[v] & 1
            else:
                if flg != seen[v] & 1:
                    ok = 0
            is_leaf[v] = 1

    if ok:
        m = 1
    else:
        m = 3
    M = N-1
    for v in range(1, N+1):
        cnt = 0
        for u in adj[v]:
            if is_leaf[u]:
                cnt += 1
        if cnt:
            M -= cnt-1
    print(m, M)


if __name__ == '__main__':
    main()