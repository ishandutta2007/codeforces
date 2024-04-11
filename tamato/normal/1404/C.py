mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.buffer.readline

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
            #if w <= 0:
            #    return 0
            x = 0
            k = 1 << (self.size.bit_length() - 1)
            while k:
                if x + k <= self.size and self.tree[x + k] < w:
                    w -= self.tree[x + k]
                    x += k
                k >>= 1
            return x + 1

    N, Q = map(int, input().split())
    A = list(map(int, input().split()))
    A = [i+1 - A[i] for i in range(N)]
    query = [[] for _ in range(N+1)]
    ans = [0] * Q
    for q in range(Q):
        x, y = map(int, input().split())
        l = x+1
        r = N-y
        query[r].append((l, q))

    bit = Bit(N+1)
    for r in range(1, N+1):
        a = A[r-1]
        if a == 0:
            bit.add(1, -1)
            bit.add(r+1, 1)
        elif a > 0:
            k = bit.lower_bound(-a+1)
            if k <= r:
                bit.add(1, -1)
                bit.add(k, 1)
        for l, q in query[r]:
            ans[q] = -bit.sum(l)
    print(*ans, sep="\n")


if __name__ == '__main__':
    main()