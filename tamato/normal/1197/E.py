mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

    N = int(input())
    A = []
    B = []
    val = set()
    val.add(0)
    a_max = -1
    for _ in range(N):
        a, b = map(int, input().split())
        a, b = b, a
        A.append(a)
        B.append(b)
        val.add(a)
        val.add(b)
        a_max = max(a_max, a)

    val = sorted(list(val))
    val2idx = {v: i for i, v in enumerate(val)}
    NN = len(val)

    adj = [[] for _ in range(NN)]
    for i in range(NN-1):
        adj[i].append((i+1, val[i+1] - val[i]))
    for a_, b_ in zip(A, B):
        a = val2idx[a_]
        b = val2idx[b_]
        adj[a].append((b, 0))

    dist = [10**10] * NN
    dist[0] = 0
    for i in range(NN-1):
        for b, cost in adj[i]:
            dist[b] = min(dist[b], dist[i] + cost)

    min_space = 10**10
    B_set = set(B)
    for b in B_set:
        if b <= a_max:
            continue
        ib = val2idx[b]
        min_space = min(min_space, dist[ib])

    dp = [0] * NN
    dp[0] = 1
    for i in range(NN - 1):
        for b, cost in adj[i]:
            if dist[i] + cost == dist[b]:
                dp[b] = (dp[b] + dp[i])%mod
    ans = 0
    for b in B_set:
        if b <= a_max:
            continue
        ib = val2idx[b]
        if dist[ib] == min_space:
            ans = (ans + dp[ib])%mod
    print(ans)


if __name__ == '__main__':
    main()