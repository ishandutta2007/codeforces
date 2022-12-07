def main():
    import sys
    input = sys.stdin.readline

    N, q = map(int, input().split())
    grid = [[0] * N for _ in range(2)]
    block = 0
    for _ in range(q):
        r, c = map(int, input().split())
        r -= 1
        c -= 1
        if grid[r][c] == 0:
            grid[r][c] = 1
            s = abs(1-r)
            block += grid[s][c]
            if c-1 >= 0:
                block += grid[s][c-1]
            if c+1 < N:
                block += grid[s][c + 1]
        else:
            grid[r][c] = 0
            s = abs(1 - r)
            block -= grid[s][c]
            if c - 1 >= 0:
                block -= grid[s][c - 1]
            if c + 1 < N:
                block -= grid[s][c + 1]
        if block:
            print('No')
        else:
            print('Yes')


if __name__ == '__main__':
    main()