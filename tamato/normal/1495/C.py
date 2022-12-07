mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def print_(grid):
        for line in grid:
            print("".join(line))

    for _ in range(int(input())):
        H, W = map(int, input().split())
        grid = [["."] * W for _ in range(H)]
        for h in range(H):
            line = input().rstrip('\n')
            for w in range(W):
                grid[h][w] = line[w]

        if H == 1:
            print("X" * W)
            continue
        elif H == 2:
            for w in range(W):
                grid[0][w] = "X"
            print_(grid)
            continue
        elif H == 3:
            for w in range(W):
                grid[1][w] = "X"
            print_(grid)
            continue

        if W == 1:
            for h in range(H):
                grid[h][0] = "X"
            print_(grid)
            continue
        elif W == 2:
            for h in range(H):
                grid[h][0] = "X"
            print_(grid)
            continue
        elif W == 3:
            for h in range(H):
                grid[h][1] = "X"
            print_(grid)
            continue

        for h in range(H):
            if h%3 == 0:
                for w in range(W):
                    grid[h][w] = "X"
        for h in range(H):
            if h%3 == 2:
                flg = 0
                for w in range(W):
                    if grid[h][w] == "X" or grid[h-1][w] == "X":
                        flg = 1
                        grid[h][w] = "X"
                        grid[h-1][w] = "X"
                        break
                if not flg:
                    grid[h][0] = "X"
                    grid[h-1][0] = "X"

        if H%3 == 0:
            for w in range(W):
                if grid[H-1][w] == "X" or grid[H-2][w] == "X":
                    grid[H-1][w] = "X"
                    grid[H-2][w] = "X"
        print_(grid)


if __name__ == '__main__':
    main()