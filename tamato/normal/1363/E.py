mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    N = int(input())
    A = [10**10]
    BC = [0]
    for _ in range(N):
        a, b, c = map(int, input().split())
        A.append(a)
        BC.append(b-c)
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
                A[u] = min(A[u], A[v])
    seq.reverse()
    pos = [0] * (N+1)
    neg = [0] * (N+1)
    ans = 0
    for v in seq:
        if BC[v] == 1:
            pos[v] += 1
        elif BC[v] == -1:
            neg[v] += 1
        for u in child[v]:
            pos[v] += pos[u]
            neg[v] += neg[u]
        k = min(pos[v], neg[v])
        ans += A[v] * k * 2
        pos[v] -= k
        neg[v] -= k
    if pos[1] == neg[1] == 0:
        print(ans)
    else:
        print(-1)


if __name__ == '__main__':
    main()