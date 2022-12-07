def main():
    import sys
    input = sys.stdin.buffer.readline

    # max
    def STfunc(a, b):
        if a > b:
            return a
        else:
            return b

    # 0-indexed[(r1, c1), (r2, c2))
    class SparseTable():
        def __init__(self, grid):
            # A: 2D
            self.N = len(grid)
            self.M = len(grid[0])
            self.KN = self.N.bit_length() - 1
            self.KM = self.M.bit_length() - 1
            self.flatten = lambda n, m, kn, km: \
                (n * self.M + m) * ((self.KN + 1) * (self.KM + 1)) + (kn * (self.KM + 1) + km)
            self.table = [0] * (self.flatten(self.N - 1, self.M - 1, self.KN, self.KM) + 1)
            for i, line in enumerate(grid):
                for j, val in enumerate(line):
                    self.table[self.flatten(i, j, 0, 0)] = val
            for km in range(1, self.KM + 1):
                for i in range(self.N):
                    for j in range(self.M):
                        j2 = j + (1 << (km - 1))
                        if j2 <= self.M - 1:
                            self.table[self.flatten(i, j, 0, km)] = \
                                STfunc(self.table[self.flatten(i, j, 0, km - 1)],
                                       self.table[self.flatten(i, j2, 0, km - 1)])
            for kn in range(1, self.KN + 1):
                for km in range(self.KM + 1):
                    for i in range(self.N):
                        i2 = i + (1 << (kn - 1))
                        for j in range(self.M):
                            if i2 <= self.N - 1:
                                self.table[self.flatten(i, j, kn, km)] = \
                                    STfunc(self.table[self.flatten(i, j, kn - 1, km)],
                                           self.table[self.flatten(i2, j, kn - 1, km)])

        def query(self, r1, c1, r2, c2):
            # [(r1, c1), (r2, c2))
            kr = (r2 - r1).bit_length() - 1
            kc = (c2 - c1).bit_length() - 1
            r2 -= (1 << kr)
            c2 -= (1 << kc)
            return STfunc(STfunc(self.table[self.flatten(r1, c1, kr, kc)], self.table[self.flatten(r2, c1, kr, kc)]),
                          STfunc(self.table[self.flatten(r1, c2, kr, kc)], self.table[self.flatten(r2, c2, kr, kc)]))

    H, W, Q = map(int, input().split())
    grid = []
    for _ in range(H):
        grid.append(input())
    #print(grid)

    R = [[0] * W for _ in range(H)]
    G = [[0] * W for _ in range(H)]
    Y = [[0] * W for _ in range(H)]
    B = [[0] * W for _ in range(H)]
    R_enc = ord('R')
    G_enc = ord('G')
    Y_enc = ord('Y')
    B_enc = ord('B')
    for h in range(H):
        for w in range(W):
            if grid[h][w] == R_enc:
                R[h][w] = 1
            elif grid[h][w] == G_enc:
                G[h][w] = 1
            elif grid[h][w] == Y_enc:
                Y[h][w] = 1
            else:
                B[h][w] = 1

    for h in range(1, H):
        for w in range(1, W):
            if R[h][w]:
                tmp = min(R[h-1][w-1], R[h-1][w], R[h][w-1]) + 1
                if tmp > 1:
                    R[h][w] = tmp
    for h in range(1, H):
        for w in range(W-2, -1, -1):
            if G[h][w]:
                tmp = min(G[h-1][w+1], G[h-1][w], G[h][w+1]) + 1
                if tmp > 1:
                    G[h][w] = tmp
    for h in range(H-2, -1, -1):
        for w in range(1, W):
            if Y[h][w]:
                tmp = min(Y[h+1][w-1], Y[h+1][w], Y[h][w-1]) + 1
                if tmp > 1:
                    Y[h][w] = tmp
    for h in range(H-2, -1, -1):
        for w in range(W-2, -1, -1):
            if B[h][w]:
                tmp = min(B[h+1][w+1], B[h+1][w], B[h][w+1]) + 1
                if tmp > 1:
                    B[h][w] = tmp

    M = [[0] * W for _ in range(H)]
    for h in range(H):
        for w in range(W):
            if h < H-1 and w < W-1:
                M[h][w] = min(R[h][w], G[h][w+1], Y[h+1][w], B[h+1][w+1])

    ST = SparseTable(M)
    ans = [None] * Q
    for q in range(Q):
        r1, c1, r2, c2 = map(int, input().split())
        r1 -= 1
        c1 -= 1
        r2 -= 1
        c2 -= 1
        ok = 0
        ng = 501
        mid = 250
        while ng - ok > 1:
            R1 = r1 + mid - 1
            C1 = c1 + mid - 1
            R2 = r2 - mid + 1
            C2 = c2 - mid + 1
            if R1 >= R2 or C1 >= C2:
                ng = mid
                mid = (ok + ng)//2
                continue
            #print(ST.query(R1, C1, R2, C2), mid, [R1, C1, R2, C2])
            if ST.query(R1, C1, R2, C2) >= mid:
                ok = mid
            else:
                ng = mid
            mid = (ok+ng)//2
        #[print(M[h]) for h in range(H)]
        ans[q] = (2*ok)**2
    sys.stdout.write('\n'.join(map(str, ans)))


if __name__ == '__main__':
    main()