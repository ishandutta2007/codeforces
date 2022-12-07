mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import deque
    input = sys.stdin.readline

    def fin():
        print(-1)
        exit()

    H, W = map(int, input().split())
    grid = []
    for _ in range(H):
        grid.append(input().rstrip('\n'))

    all_white_row = 0
    for h in range(H):
        if "#" not in grid[h]:
            all_white_row = 1
            continue
        if grid[h][0] == "#":
            flg = 0
            for w in range(W):
                if flg == 0:
                    if grid[h][w] == ".":
                        flg = 1
                else:
                    if grid[h][w] == "#":
                        fin()
        else:
            flg = 0
            for w in range(W):
                if flg == 0:
                    if grid[h][w] == "#":
                        flg = 1
                elif flg == 1:
                    if grid[h][w] == ".":
                        flg = 2
                else:
                    if grid[h][w] == "#":
                        fin()

    all_white_col = 0
    for w in range(W):
        if grid[0][w] == "#":
            flg = 0
            for h in range(H):
                if flg == 0:
                    if grid[h][w] == ".":
                        flg = 1
                else:
                    if grid[h][w] == "#":
                        fin()
        else:
            flg = 0
            for h in range(H):
                if flg == 0:
                    if grid[h][w] == "#":
                        flg = 1
                elif flg == 1:
                    if grid[h][w] == ".":
                        flg = 2
                else:
                    if grid[h][w] == "#":
                        fin()
            if flg == 0:
                all_white_col = 1

    if all_white_col ^ all_white_row:
        fin()

    que = deque()
    seen = [[0] * W for _ in range(H)]
    ans = 0
    d = [(0, 1), (0, -1), (1, 0), (-1, 0)]
    for h in range(H):
        for w in range(W):
            if grid[h][w] == "#" and seen[h][w] == 0:
                ans += 1
                que.append((h, w))
                seen[h][w] = 1
                while que:
                    h, w = que.popleft()
                    for dh, dw in d:
                        h_new, w_new = h+dh, w+dw
                        if 0 <= h_new < H and 0 <= w_new < W:
                            if grid[h_new][w_new] == "#" and seen[h_new][w_new] == 0:
                                seen[h_new][w_new] = 1
                                que.append((h_new, w_new))
    print(ans)


if __name__ == '__main__':
    main()