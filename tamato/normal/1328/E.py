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
                self.table[i][0] = a
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

    N, M = map(int, input().split())
    adj = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
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

    for _ in range(M):
        v_list = list(map(int, input().split()))
        vd = [(v, depth[v]) for v in v_list[1:]]
        vd.sort(key=lambda x: x[1])
        ok = 1
        L = len(vd)
        for i in range(L-1):
            a, da = vd[i]
            b, db = vd[i+1]
            lca_depth = ST.query(min(left[a], left[b]), max(right[a], right[b]) + 1)
            if lca_depth < min(da, db)-1:
                ok = 0
                break
        if ok:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()