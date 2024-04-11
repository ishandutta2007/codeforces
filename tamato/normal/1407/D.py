mod = 1000000007
eps = 10**-9
inf = 10**9


def main():
    import sys
    input = sys.stdin.readline

    class Bit:
        def __init__(self, n):
            self.size = n
            self.tree = [0] * (n + 1)

        def sum(self, i):
            s = 0
            while i > 0:
                s += self.tree[i]
                i -= i & -i
            return s

        def add(self, i, x):
            while i <= self.size:
                self.tree[i] += x
                i += i & -i

        def lower_bound(self, w):
            if w <= 0:
                return 0
            x = 0
            k = 1 << (self.size.bit_length() - 1)
            while k:
                if x + k <= self.size and self.tree[x + k] < w:
                    w -= self.tree[x + k]
                    x += k
                k >>= 1
            return x + 1

    N = int(input())
    A = list(map(int, input().split()))

    adj = [[] for _ in range(N+1)]

    AA = sorted(list(set(A)))
    a2i = {a:i for i, a in enumerate(AA)}

    AI = [[] for _ in range(len(AA))]
    for i, a in enumerate(A):
        ii = a2i[a]
        AI[ii].append(i+1)
    bit_high = Bit(N)
    for i_list in AI:
        for i in i_list:
            bit_high.add(i, 1)
        for i in i_list:
            val = bit_high.sum(i)
            il = bit_high.lower_bound(val - 1)
            ir = bit_high.lower_bound(val + 1)
            if il > 0:
                adj[il].append(i)
            if ir <= N:
                adj[i].append(ir)

    bit_low = Bit(N)
    AI.reverse()
    for i_list in AI:
        for i in i_list:
            bit_low.add(i, 1)
        for i in i_list:
            val = bit_low.sum(i)
            il = bit_low.lower_bound(val - 1)
            ir = bit_low.lower_bound(val + 1)
            if il > 0:
                adj[il].append(i)
            if ir <= N:
                adj[i].append(ir)

    dp = [inf] * (N+1)
    dp[1] = 0
    for i in range(1, N+1):
        for j in adj[i]:
            dp[j] = min(dp[j], dp[i] + 1)
    print(dp[N])


if __name__ == '__main__':
    main()