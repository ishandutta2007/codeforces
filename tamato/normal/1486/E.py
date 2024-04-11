mod = 1000000007
eps = 10**-9
inf = 1 << 60


def main():
    import sys
    input = sys.stdin.buffer.readline
    import heapq

    def dijkstra(adj, start):
        # adj: [[to, cost] * vertices], 0th index must be empty
        N = len(adj) - 1
        dist = [inf] * (N * 51 + 1)
        dist[start] = 0
        q = []
        heapq.heappush(q, (0, start))
        while q:
            min_dist, v_from = heapq.heappop(q)
            if min_dist > dist[v_from]:
                continue
            if v_from <= N:
                for v_to_, cost in adj[v_from]:
                    v_to = v_to_ + N * cost
                    if min_dist < dist[v_to]:
                        dist[v_to] = min_dist
                        heapq.heappush(q, (dist[v_to], v_to))
            else:
                prev_w = (v_from - 1) // N
                v_from -= prev_w * N
                for v_to, cost in adj[v_from]:
                    cost_new = min_dist + (cost + prev_w) ** 2
                    if cost_new < dist[v_to]:
                        dist[v_to] = cost_new
                        heapq.heappush(q, (cost_new, v_to))
        return dist[:N+1]

    N, M = map(int, input().split())
    adj = [[] for _ in range(N+1)]
    for _ in range(M):
        u, v, w = map(int, input().split())
        adj[u].append((v, w))
        adj[v].append((u, w))

    dist = dijkstra(adj, 1)
    for i in range(1, N+1):
        if dist[i] >= inf:
            dist[i] = -1
    print(*dist[1:])


if __name__ == '__main__':
    main()