def main():
    import sys
    input = sys.stdin.buffer.readline

    # min
    def STfunc(a, b):
        if a < b:
            return a
        else:
            return b

    # 0-indexed[l, r)
    class SparseTable():
        def __init__(self, A):
            # A: 
            self.N = len(A)
            self.K = self.N.bit_length() - 1
            self.table = [[0] * (self.K + 1) for _ in range(self.N)]
            for i, a in enumerate(A):
                self.table[i][0] = A[i]
            for k in range(1, self.K + 1):
                for i in range(self.N):
                    j = i + (1 << (k - 1))
                    if j <= self.N - 1:
                        self.table[i][k] = STfunc(self.table[i][k - 1], self.table[j][k - 1])
                    else:
                        self.table[i][k] = self.table[i][k - 1]

        def query(self, l, r):
            # [l, r)
            k = (r - l).bit_length() - 1
            return STfunc(self.table[l][k], self.table[r - (1 << k)][k])

    # adj[0] must be empty list
    def EulerTour(adj, root):
        st = [root]
        ret = []
        seen = [0] * len(adj)
        par = [0] * len(adj)
        depth = [0] * len(adj)
        while st:
            v = st.pop()
            if seen[v]:
                ret.append(v)
                continue
            ret.append(v)
            seen[v] = 1
            if par[v] != 0:
                st.append(par[v])
            for u in adj[v]:
                if seen[u] == 0:
                    st.append(u)
                    par[u] = v
                    depth[u] = depth[v] + 1

        return ret, depth

    N = int(input())
    adj = [[] for _ in range(N+1)]
    for _ in range(N-1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)

    et, depth = EulerTour(adj, 1)
    depth_list = [0] * len(et)
    left = [-1] * (N + 1)
    right = [-1] * (N + 1)
    for i, v in enumerate(et):
        depth_list[i] = depth[v]
        if left[v] < 0:
            left[v] = i
        right[v] = i
    ST = SparseTable(depth_list)

    q = int(input())
    for i in range(q):
        x, y, a, b, k = map(int, input().split())
        lca_depth_AB = ST.query(min(left[a], left[b]), max(right[a], right[b]) + 1)
        AB = depth[a] + depth[b] - 2 * lca_depth_AB
        if k >= AB and (k-AB)%2 == 0:
            print('YES')
            continue
        lca_depth_AX = ST.query(min(left[a], left[x]), max(right[a], right[x]) + 1)
        AX = depth[a] + depth[x] - 2 * lca_depth_AX
        lca_depth_BY = ST.query(min(left[b], left[y]), max(right[b], right[y]) + 1)
        BY = depth[b] + depth[y] - 2 * lca_depth_BY
        AB_new = AX + BY + 1
        if k >= AB_new and (k-AB_new)%2 == 0:
            print('YES')
            continue
        lca_depth_AY = ST.query(min(left[a], left[y]), max(right[a], right[y]) + 1)
        AY = depth[a] + depth[y] - 2 * lca_depth_AY
        lca_depth_BX = ST.query(min(left[b], left[x]), max(right[b], right[x]) + 1)
        BX = depth[b] + depth[x] - 2 * lca_depth_BX
        AB_new = AY + BX + 1
        if k >= AB_new and (k-AB_new)%2 == 0:
            print('YES')
            continue
        print('NO')


if __name__ == '__main__':
    main()