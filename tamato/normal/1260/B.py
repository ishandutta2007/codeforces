def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    for _ in range(N):
        a, b = map(int, input().split())
        ok = 1
        x1 = 2*b-a
        x2 = 2*a-b
        if x1 % 3 != 0 or x1 < 0:
            ok = 0
        if x2 % 3 != 0 or x2 < 0:
            ok = 0
        if ok:
            print('YES')
        else:
            print('NO')


if __name__ == '__main__':
    main()