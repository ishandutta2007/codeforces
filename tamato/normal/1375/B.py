mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline
    
    for _ in range(int(input())):
        H, W = map(int, input().split())
        grid = []
        for _ in range(H):
            grid.append(list(map(int, input().split())))

        ans = [[4] * W for _ in range(H)]
        ans[0][0] = 2
        ans[0][W-1] = 2
        ans[H-1][0] = 2
        ans[H-1][W-1] = 2
        for w in range(1, W-1):
            ans[0][w] = 3
            ans[-1][w] = 3
        for h in range(1, H-1):
            ans[h][0] = 3
            ans[h][-1] = 3
        flg = 1
        for h in range(H):
            if flg == 0:
                break
            for w in range(W):
                if ans[h][w] < grid[h][w]:
                    flg = 0
                    break
        if flg:
            print("YES")
            for h in range(H):
                print(*ans[h])
        else:
            print("NO")


if __name__ == '__main__':
    main()