mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    N, M = map(int, input().split())
    n1, n2, n3 = map(int, input().split())
    adj = [[] for _ in range(N+1)]
    for _ in range(M):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)


    seen = [-1] * (N+1)
    BW = []
    for v0 in range(1, N+1):
        if seen[v0] != -1:
            continue
        que = deque()
        que.append(v0)
        seen[v0] = 0
        B = [v0]
        W = []
        while que:
            v = que.popleft()
            for u in adj[v]:
                if seen[u] == -1:
                    seen[u] = seen[v] ^ 1
                    if seen[u] == 0:
                        B.append(u)
                    else:
                        W.append(u)
                    que.append(u)
                else:
                    if seen[u] == seen[v]:
                        print("NO")
                        exit()
        BW.append((B, W))

    G = len(BW)
    dp = [[0] * (n2+1) for _ in range(G+1)]
    dp[0][0] = 1
    for i in range(G):
        b = len(BW[i][0])
        w = len(BW[i][1])
        for j in range(n2+1):
            if dp[i][j]:
                if j+b <= n2:
                    dp[i+1][j+b] = 1
                if j+w <= n2:
                    dp[i+1][j+w] = 1
    if not dp[-1][n2]:
        print("NO")
        exit()

    val = n2
    ans = [0] * (N+1)
    for i in range(G-1, -1, -1):
        b = len(BW[i][0])
        w = len(BW[i][1])
        ok = 0
        if val - b >= 0:
            if dp[i][val - b]:
                val -= b
                for v in BW[i][0]:
                    ans[v] = 2
                ok = 1
        if not ok:
            if val - w >= 0:
                if dp[i][val - w]:
                    val -= w
                    for v in BW[i][1]:
                        ans[v] = 2
    flg = n1
    for i in range(1, N+1):
        if ans[i] == 0:
            if flg:
                ans[i] = 1
                flg -= 1
            else:
                ans[i] = 3
    print("YES")
    print("".join(map(str, ans[1:])))


if __name__ == '__main__':
    main()