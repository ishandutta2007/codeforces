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

    N = int(input())
    X = list(map(int, input().split()))
    V = list(map(int, input().split()))

    info = [(x, v) for x, v in zip(X, V)]
    info.sort(key=lambda p: p[0])
    info.sort(key=lambda p: p[1])
    X.sort()
    x2i = {x: i+1 for i, x in enumerate(X)}
    bit_x = Bit(N+1)
    bit_cnt = Bit(N+1)

    ans = 0
    for x, _ in info:
        i = x2i[x]
        ans += bit_cnt.sum(i) * x - bit_x.sum(i)
        bit_x.add(i, x)
        bit_cnt.add(i, 1)
    print(ans)


if __name__ == '__main__':
    main()