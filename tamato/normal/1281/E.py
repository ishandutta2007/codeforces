def main():
    import sys
    input = sys.stdin.buffer.readline
    
    t = int(input())
    for _ in range(t):
        K = int(input())
        N = 2*K
        adj = [[] for _ in range(N+1)]
        edge = []
        for _ in range(N-1):
            a, b, t = map(int, input().split())
            adj[a].append((b, t))
            adj[b].append((a, t))
        
        
        st = [1]
        seen = [0] * (N+1)
        seen[1] = 1
        par_t = [0] * (N+1)
        child = [[] for _ in range(N+1)]
        seq = []
        while st:
            v = st.pop()
            seq.append(v)
            for u, t in adj[v]:
                if not seen[u]:
                    seen[u] = 1
                    st.append(u)
                    par_t[u] = t
                    child[v].append(u)
        seq.reverse()
        
        G = B = 0
        dp = [1] * (N+1)
        for v in seq:
            for u in child[v]:
                dp[v] += dp[u]
            m = min(dp[v], N - dp[v])
            G += par_t[v] * (m % 2)
            B += par_t[v] * m
        print(G, B)
        

if __name__ == '__main__':
    main()