mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.buffer.readline

    for t in range(int(input())):
        N, a, b, da, db = map(int, input().split())
        adj = [[] for _ in range(N+1)]
        for _ in range(N-1):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)

        if db < 2*da+1:
            print("Alice")
            continue

        que = deque()
        que.append(a)
        seen = [-1] * (N+1)
        seen[a] = 0
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

        #print(t, seen, a, b, adj)
        if seen[b] <= da:
            print("Alice")
            continue

        c = seq[0]
        que2 = deque()
        que2.append(c)
        seen2 = [-1] * (N+1)
        seen2[c] = 0
        par2 = [0] * (N+1)
        child2 = [[] for _ in range(N+1)]
        seq2 = []
        while que2:
            v = que2.popleft()
            seq2.append(v)
            for u in adj[v]:
                if seen2[u] == -1:
                    seen2[u] = seen2[v] + 1
                    par2[u] = v
                    child2[v].append(u)
                    que2.append(u)
        seq2.reverse()

        if seen2[seq2[0]] < da*2+1:
            print("Alice")
        else:
            print("Bob")


if __name__ == '__main__':
    main()