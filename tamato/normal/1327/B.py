def main():
    import sys
    input = sys.stdin.readline

    T = int(input())
    for t in range(T):
        N = int(input())
        seen = [0] * (N+1)
        lines = []
        for i in range(1, N+1):
            lines.append(list(map(int, input().split())))
        ii = 0
        for i in range(1, N+1):
            line = lines[i-1][1:]
            flg = 1
            for j in line:
                if not seen[j]:
                    flg = 0
                    seen[j] = 1
                    break
            if flg:
                ii = i
        if ii:
            for j in range(1, N+1):
                if not seen[j]:
                    print('IMPROVE')
                    print(ii, j)
                    break
        else:
            print('OPTIMAL')


if __name__ == '__main__':
    main()