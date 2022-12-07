def main():
    import sys
    input = sys.stdin.readline

    N, M = map(int, input().split())
    grid = []
    for _ in range(N):
        grid.append(input().rstrip('\n'))

    cnt = [0] * M
    for line in grid:
        for m in range(M):
            if line[m] == '1':
                cnt[m] += 1
    for i in range(N):
        line = grid[i]
        need = 0
        for j in range(M):
            if line[j] == '1':
                if cnt[j] == 1:
                    need = 1
                    break
        if not need:
            print('YES')
            exit()
    print('NO')


if __name__ == '__main__':
    main()