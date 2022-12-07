def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(list(map(int, input().split())))

    ans = []
    B = [[0] * M for _ in range(N)]
    for i in range(N-1):
        for j in range(M-1):
            if grid[i][j] == grid[i+1][j] == grid[i][j+1] == grid[i+1][j+1] == 1:
                ans.append((i+1, j+1))
                B[i][j] = 1
                B[i+1][j] = 1
                B[i][j+1] = 1
                B[i+1][j+1] = 1
    for i in range(N):
        for j in range(M):
            if grid[i][j] != B[i][j]:
                print(-1)
                exit()
    print(len(ans))
    for line in ans:
        print(*line)


if __name__ == '__main__':
    main()