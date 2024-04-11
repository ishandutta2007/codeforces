def main():
    import sys
    input = sys.stdin.buffer.readline

    for t in range(int(input())):
        l, r, d, u = map(int, input().split())
        x, y, x1, y1, x2, y2 = map(int, input().split())
        X, Y = x + (r - l), y + (u - d)
        if X < x1 or X > x2 or Y < y1 or Y > y2:
            print('No')
        else:
            ok = 1
            if x1 == x2:
                if l != 0 or r != 0:
                    ok = 0
            if y1 == y2:
                if u!=0 or d != 0:
                    ok = 0
            if ok:
                print('Yes')
            else:
                print('No')


if __name__ == '__main__':
    main()