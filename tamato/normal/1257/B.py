def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        x, y = map(int, input().split())
        if x >= 4:
            print('YES')
        elif x == 2 or x == 3:
            if y <= 3:
                print('YES')
            else:
                print('NO')
        elif x == 1:
            if y == 1:
                print('YES')
            else:
                print('NO')


if __name__ == '__main__':
    main()