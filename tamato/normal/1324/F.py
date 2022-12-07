def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    A = list(map(int, input().split()))
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)

    """"""

    # op: DP
    def op(a, b):
        return a + max(0, b)

    # (op(x, ident) = x)(CE)
    ident_op = 0

    # cum_merge: op
    def cum_merge(a, b):
        return a + b

    # (cum_merge(x, ident) = x)
    ident_cum_merge = 0
    """"""

    # root=1DP
    # op
    # (from_par)
    def Rerooting(adj):
        N = len(adj) - 1
        st = [1]
        seen = [0] * (N + 1)
        seen[1] = 1
        par = [0] * (N + 1)
        child = [[] for _ in range(N + 1)]
        seq = []
        while st:
            v = st.pop()
            seq.append(v)
            for u in adj[v]:
                if not seen[u]:
                    seen[u] = 1
                    par[u] = v
                    child[v].append(u)
                    st.append(u)
        seq.reverse()
        dp = [ident_op] * (N+1)
        left = [ident_cum_merge] * (N + 1)
        right = [ident_cum_merge] * (N + 1)
        for v in seq:
            tmp = ident_cum_merge
            for u in child[v]:
                left[u] = tmp
                tmp = op(tmp, dp[u])
            tmp = ident_cum_merge
            for u in reversed(child[v]):
                right[u] = tmp
                tmp = op(tmp, dp[u])
            dp[v] = tmp
            if A[v-1]:
                dp[v] += 1
            else:
                dp[v] -= 1

        seq.reverse()
        from_par = [ident_op] * (N + 1)
        for v in seq:
            if v == 1:
                continue
            from_par[v] = op(cum_merge(left[v], right[v]), from_par[par[v]])
            if A[par[v]-1]:
                from_par[v] += 1
            else:
                from_par[v] -= 1
            dp[v] = op(dp[v], from_par[v])

        return dp

    dp = Rerooting(adj)
    print(*dp[1:])


if __name__ == '__main__':
    main()