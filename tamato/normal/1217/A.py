def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        s, i, e = map(int, input().split())
        if e == 0:
            print(int(s>i))
            continue
        ok = -2
        ng = e+1
        mid = (ok+ng)//2
        while ng - ok > 1:
            if s + (e - mid) > i + mid:
                ok = mid
            else:
                ng = mid
            mid = (ok+ng)//2
        if ok >= 0:
            print(ok+1)
        else:
            print(0)


if __name__ == '__main__':
    main()