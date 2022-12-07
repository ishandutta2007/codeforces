def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    adj = [[] for _ in range(N+1)]
    E = {}
    for i in range(N-1):
        a, b = map(int, input().split())
        adj[a].append(b)
        adj[b].append(a)
        E[a*(N+1)+b] = i
        E[b*(N+1)+a] = i
    flg = 0
    ans = [-1] * (N-1)
    for v in range(1, N+1):
        if len(adj[v]) >= 3:
            for i, u in enumerate(adj[v][:3]):
                ans[E[u*(N+1)+v]] = i
            flg = 1
            break
    if flg:
        j = 3
        for i in range(N-1):
            if ans[i] == -1:
                ans[i] = j
                j += 1
    else:
        ans = list(range(N-1))
    print('\n'.join(map(str, ans)))



if __name__ == '__main__':
    main()