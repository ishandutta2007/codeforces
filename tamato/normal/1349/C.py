def main():
    import sys
    from array import array
    from collections import deque
    input = sys.stdin.readline

    H, W, Q = map(int, input().split())
    grid = array('b', [0] * (H*W))
    #flg_0 = 0
    #flg_1 = 0
    for h in range(H):
        line = input().rstrip('\n')
        """
        if "0" in line:
            flg_0 = 1
        if "1" in line:
            flg_1 = 1
        """
        for w in range(W):
            if line[w] == "1":
                grid[h*W + w] ^= 1

    """
    if flg_0 == 0:
        for _ in range(Q):
            print(1)
        exit()
    if flg_1 == 0:
        for _ in range(Q):
            print(0)
        exit()
    """

    que = deque()
    start_change = [-1] * (H*W)
    d = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for h in range(H):
        for w in range(W):
            same = 0
            hw = h*W+w
            for dh, dw in d:
                h_new, w_new = h+dh, w+dw
                hw_new = h_new * W + w_new
                if 0 <= h_new < H and 0 <= w_new < W:
                    if grid[hw] == grid[hw_new]:
                        same = 1
                        break
            if same:
                que.append(hw)
                start_change[hw] = 0

    while que:
        hw = que.popleft()
        h, w = divmod(hw, W)
        for dh, dw in d:
            h_new, w_new = h + dh, w + dw
            hw_new = h_new * W + w_new
            if 0 <= h_new < H and 0 <= w_new < W:
                if start_change[hw_new] == -1:
                    start_change[hw_new] = start_change[hw] + 1
                    que.append(hw_new)

    for _ in range(Q):
        h, w, p = map(int, input().split())
        h -= 1
        w -= 1
        hw = h*W + w
        if start_change[hw] == -1:
            print(grid[hw])
            continue
        if p <= start_change[hw]:
            print(grid[hw])
        else:
            if (p - start_change[hw]) % 2 == 0:
                print(grid[hw])
            else:
                print(grid[hw] ^ 1)


if __name__ == '__main__':
    main()