mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    N, K = map(int, input().split())
    P = list(map(int, input().split()))
    nxt = [-1] * (N+1)
    prev = [-1] * (N+1)
    adj = [[] for _ in range(N + 1)]
    for _ in range(K):
        x, y = map(int, input().split())
        nxt[x] = y
        prev[y] = x
        adj[x].append(y)

    for i, p in enumerate(P):
        if p != 0:
            adj[p].append(i+1)
    for v in range(1, N+1):
        r = v
        r_list = [r]
        while prev[r] != -1:
            r = prev[r]
            r_list.append(r)
            if r == v:
                print(0)
                exit()
        for u in r_list[:-1]:
            prev[u] = r
    for v in range(1, N+1):
        if prev[v] != -1:
            r = prev[v]
            p = P[v-1]
            if prev[p] != r and p != r:
                adj[p].append(r)

    in_num = [0] * (N+1)
    for v in range(1, N+1):
        for u in adj[v]:
            in_num[u] += 1
    st = []
    for v in range(1, N+1):
        if in_num[v] == 0:
            st.append(v)

    ans = []
    seen = [0] * (N+1)
    while st:
        v = st.pop()
        if seen[v]:
            continue
        else:
            seen[v] = 1
        ans.append(v)
        for u in adj[v]:
            in_num[u] -= 1
            if in_num[u] == 0:
                st.append(u)
        if nxt[v] != -1:
            if in_num[nxt[v]] != 0:
                break
            st.append(nxt[v])
    #print(ans)
    #print(adj)
    if len(ans) != N:
        print(0)
    else:
        print(*ans)




if __name__ == '__main__':
    main()