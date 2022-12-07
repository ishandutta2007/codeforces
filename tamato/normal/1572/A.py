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

    for _ in range(int(input())):
        N = int(input())
        adj = [[] for _ in range(N+1)]
        in_num = [0] * (N+1)
        for i in range(1, N+1):
            L = list(map(int, input().split()))
            if len(L) != 1:
                for j in range(1, len(L)):
                    k = L[j]
                    adj[k].append(i)
                    in_num[i] += 1

        bit = Bit(N)
        for i in range(1, N+1):
            if in_num[i] == 0:
                bit.add(i, 1)
        cnt = N
        ans = 0
        j_cur = N+1
        while cnt:
            if j_cur > N:
                ans += 1
                if ans > N:
                    break
                j_cur = 0
            if j_cur:
                j = bit.lower_bound(bit.sum(j_cur) + 1)
            else:
                j = bit.lower_bound(1)
            if j <= N:
                bit.add(j, -1)
                cnt -= 1
                for u in adj[j]:
                    in_num[u] -= 1
                    if in_num[u] == 0:
                        bit.add(u, 1)
            j_cur = j
        if ans > N:
            print(-1)
        else:
            print(ans)


if __name__ == '__main__':
    main()