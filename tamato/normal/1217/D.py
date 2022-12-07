def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    N, M = map(int, input().split())
    adj = [[] for _ in range(N+1)]
    edge = {}
    in_num = [0] * (N+1)
    for i in range(M):
        a, b = map(int, input().split())
        adj[a].append(b)
        edge[a*(N+1)+b] = i
        in_num[b] += 1

    ans = [1] * M
    que = deque()
    for i in range(1, N+1):
        if in_num[i] == 0:
            que.append(i)
    j = 0
    cnt = 0
    while True:
        while que:
            v = que.pop()
            cnt += 1
            for u in adj[v]:
                in_num[u] -= 1
                if in_num[u] == 0:
                    que.append(u)
        if cnt == N:
            break
        else:
            while True:
                if in_num[j] <= 0:
                    j += 1
                else:
                    break
            in_num[j] = -1
            cnt += 1
            for u in adj[j]:
                ans[edge[j*(N+1)+u]] = 2
                in_num[u] -= 1
                if in_num[u] == 0:
                    que.append(u)
                elif in_num[u] < 0:
                    ans[edge[j*(N+1)+u]] = 1
            #print(ans, j)

    print(max(ans))
    print(*ans)


if __name__ == '__main__':
    main()