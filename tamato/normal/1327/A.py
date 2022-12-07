def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, K = map(int, input().split())
        ok = 1
        if N%2 != K%2:
            ok = 0
        if N < K * K:
            ok = 0
        if ok:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()