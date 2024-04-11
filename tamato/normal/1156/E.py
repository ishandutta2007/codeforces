mod = 1000000007
eps = 10**-9


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
    P = list(map(int, input().split()))

    idx = [0] * (N+1)
    for i, p in enumerate(P):
        idx[p] = i+1
    bit = Bit(N)
    ans = 0
    for p in range(N, 0, -1):
        i = idx[p]
        k = bit.sum(i)
        r = bit.lower_bound(k+1)
        l = bit.lower_bound(k)
        nl = i - l - 1
        nr = r - i - 1
        if nl < nr:
            for j in range(l+1, i):
                q = P[j-1]
                if i < idx[p - q] < r:
                    ans += 1
        else:
            for j in range(i+1, r):
                q = P[j-1]
                if l < idx[p - q] < i:
                    ans += 1
        bit.add(i, 1)
        #print(l, r)
    print(ans)


if __name__ == '__main__':
    main()