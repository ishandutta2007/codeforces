mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    from itertools import accumulate
    input = sys.stdin.buffer.readline

    for _ in range(int(input())):
        N, S = map(int, input().split())
        adj = [[] for _ in range(N+1)]
        for _ in range(N-1):
            a, b, c, d = map(int, input().split())
            adj[a].append((b, c, d))
            adj[b].append((a, c, d))
        que = deque()
        que.append(1)
        seen = [-1] * (N+1)
        seen[1] = 0
        par = [0] * (N+1)
        child = [[] for _ in range(N+1)]
        seq = []
        C = [0] * (N+1)
        D = [0] * (N+1)
        while que:
            v = que.popleft()
            seq.append(v)
            for u, c, d in adj[v]:
                if seen[u] == -1:
                    seen[u] = seen[v] + 1
                    par[u] = v
                    child[v].append(u)
                    que.append(u)
                    C[u] = c
                    D[u] = d
        seq.reverse()
        dp = [0] * (N+1)
        T = 0
        D1_ = [[] for _ in range(40)]
        D2_ = [[] for _ in range(40)]
        for v in seq:
            if not child[v]:
                dp[v] = 1
            else:
                for u in child[v]:
                    dp[v] += dp[u]
            c = C[v]
            d = D[v]
            num = dp[v]
            T += c * num
            while c:
                val = (c+1)//2 * num
                k = len(bin(val)) - 2
                if d == 1:
                    D1_[k].append(val)
                else:
                    D2_[k].append(val)
                c //= 2
        for i in range(40):
            D1_[i].sort(reverse=True)
            D2_[i].sort(reverse=True)
        D1 = []
        D2 = []
        for i in range(39, -1, -1):
            D1.extend(D1_[i])
            D2.extend(D2_[i])
        cs_D1 = [0] + list(accumulate(D1))
        cs_D2 = [0] + list(accumulate(D2))
        i1 = len(D1) + 1
        i2 = 0
        ans = len(D1) + len(D2) * 2
        flg = 0
        for _ in range(len(D1) + 1):
            i1 -= 1
            t = T - cs_D1[i1] - cs_D2[i2]
            while t > S:
                i2 += 1
                if i2 == len(cs_D2):
                    flg = 1
                    break
                t = T - cs_D1[i1] - cs_D2[i2]
            if flg:
                break
            ans = min(ans, i1+i2*2)
        print(ans)


if __name__ == '__main__':
    main()