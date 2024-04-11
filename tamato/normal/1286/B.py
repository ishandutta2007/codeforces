mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    N = int(input())
    par = [0] * (N+1)
    child = [[] for _ in range(N+1)]
    C = [0] * (N+1)
    for v in range(1, N+1):
        p, c = map(int, input().split())
        par[v] = p
        C[v] = c
        child[p].append(v)
        if p == 0:
            root = v

    que = deque()
    que.append(root)
    seq = []
    while que:
        v = que.popleft()
        seq.append(v)
        for u in child[v]:
            que.append(u)
    seq.reverse()
    size = [1] * (N+1)
    for v in seq:
        for u in child[v]:
            size[v] += size[u]

    order = [[] for _ in range(N+1)]
    for v in seq:
        if C[v] > size[v] - 1:
            print("NO")
            exit()
        for u in child[v]:
            order[v].extend(order[u])
        order[v].insert(C[v], v)

    print("YES")
    ans = [0] * N
    for i, v in enumerate(order[root]):
        ans[v-1] = i+1
    print(*ans)


if __name__ == '__main__':
    main()