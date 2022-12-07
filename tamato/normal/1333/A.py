def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, M = map(int, input().split())
        ans = [['B'] * M for _ in range(N)]
        for i in range(N):
            for j in range(M):
                if (i+j) & 1:
                    ans[i][j] = 'W'
        if (N*M)&1 == 0:
            if ans[-1][-1] == 'W':
                ans[-1][-1] = 'B'
            else:
                ans[0][-1] = 'B'
        for i in range(N):
            print(''.join(ans[i]))


if __name__ == '__main__':
    main()