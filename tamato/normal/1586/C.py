mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    H, W = map(int, input().split())
    grid = []
    for _ in range(H):
        grid.append(input().rstrip('\n'))

    A = [0] * W
    for w in range(W-1):
        for h in range(1, H):
            if grid[h][w] == "X" and grid[h-1][w+1] == "X":
                A[w] = 1
                break
    cs = [0] * (W+1)
    for w in range(W):
        cs[w+1] = cs[w] + A[w]

    for _ in range(int(input())):
        w1, w2 = map(int, input().split())
        if w1 == w2:
            print("YES")
        else:
            if cs[w2 - 1] - cs[w1 - 1] > 0:
                print("NO")
            else:
                print("YES")


if __name__ == '__main__':
    main()