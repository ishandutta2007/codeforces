def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    N = int(input())
    color = list(map(int, input().split()))
    color.insert(0, 0)
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
    seq.reverse()

    cnt = [{color[i]: 1} for i in range(N+1)]
    cnt_size = [1] * (N+1)
    dom_num = [1] * (N+1)
    ans = [color[i] for i in range(N+1)]
    for v in seq:
        big = cnt[v]
        size_big = cnt_size[v]
        for u in child[v]:
            small = cnt[u]
            size_small = cnt_size[u]
            if size_big < size_small:
                small, big = big, small
                dom_num[v] = dom_num[u]
                ans[v] = ans[u]
            size_big += size_small
            for c in small:
                if c not in big:
                    big[c] = small[c]
                else:
                    big[c] += small[c]
                cnt_size[v] += small[c]
                if big[c] > dom_num[v]:
                    dom_num[v] = big[c]
                    ans[v] = c
                elif big[c] == dom_num[v]:
                    ans[v] += c
        cnt_size[v] = size_big
        cnt[v] = big
    print(*ans[1:])
    #print(child)
    #print(cnt)
    #print(cnt_size)


if __name__ == '__main__':
    main()