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

    N = int(input())
    A = list(map(int, input().split()))

    bit = Bit(N)
    bit.add(1, A[0])
    b = A[0]
    ans = []
    for i in range(1, N):
        bit.add(i+1, A[i] - A[i-1])
        if A[i] - A[i-1] > 0:
            b += A[i] - A[i-1]
    ans.append((b+1)//2)

    for _ in range(int(input())):
        l, r, x = map(int, input().split())
        if l != 1:
            dl_ori = bit.sum(l) - bit.sum(l-1)
            dl_new = dl_ori + x
            dl_ori = max(0, dl_ori)
            dl_new = max(0, dl_new)
            b += dl_new - dl_ori
        else:
            b += x
        if r != N:
            dr_ori = bit.sum(r+1) - bit.sum(r)
            dr_new = dr_ori - x
            dr_ori = max(0, dr_ori)
            dr_new = max(0, dr_new)
            b += dr_new - dr_ori
        bit.add(l, x)
        if r != N:
            bit.add(r+1, -x)
        ans.append((b+1) // 2)
    print(*ans, sep="\n")


if __name__ == '__main__':
    main()