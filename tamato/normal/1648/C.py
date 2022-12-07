mod = 998244353
eps = 10**-9
NN = 200000


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

    fac = [1] * (2 * 10 ** 5 + 1)
    for i in range(2, 2 * 10 ** 5 + 1):
        fac[i] = (fac[i - 1] * i) % mod

    N, M = map(int, input().split())
    S = list(map(int, input().split()))
    T = list(map(int, input().split()))

    T.append(0)
    bit = Bit(NN)
    cnt = [0] * (NN + 1)
    for s in S:
        bit.add(s, 1)
        cnt[s] += 1
    SS = []
    for i in range(1, NN + 1):
        if cnt[i] > 1:
            SS.append(cnt[i])
    ans = 0
    x = 1
    for i in range(min(N, M + 1)):
        t = T[i]
        if t == 0:
            break
        if t > 1:
            tmp = (bit.sum(t - 1) * fac[N - i - 1] * x) % mod
            ans = (ans + tmp) % mod
        if cnt[t] == 0:
            break
        else:
            x = (x * cnt[t])%mod
            cnt[t] -= 1
            bit.add(t, -1)

    if N < M:
        if sorted(S) == sorted(T[:N]):
            ans = (ans + x)%mod

    tmp = 1
    for s in SS:
        tmp = (tmp * fac[s]) % mod
    print((ans * pow(tmp, mod - 2, mod)) % mod)


if __name__ == '__main__':
    main()