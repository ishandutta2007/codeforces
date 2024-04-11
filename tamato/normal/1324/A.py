def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        flg = A[0] & 1
        ok = 1
        for a in A:
            if a&1 != flg:
                ok = 0
        if ok:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()