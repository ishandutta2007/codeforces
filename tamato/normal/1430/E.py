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
    S = input().rstrip('\n')
    S_rev = S[::-1]

    idx = [[] for _ in range(26)]
    for i, s in enumerate(S):
        idx[ord(s) - 97].append(i)

    cnt = [0] * 26
    A = [0] * N
    for i, s in enumerate(S_rev):
        si = ord(s) - 97
        A[idx[si][cnt[si]]] = i
        cnt[si] += 1

    a2i = {a: i+1 for i, a in enumerate(A)}
    bit = Bit(N)
    ans = 0
    for a in range(N-1, -1, -1):
        ans += bit.sum(a2i[a])
        bit.add(a2i[a], 1)
    print(ans)


if __name__ == '__main__':
    main()