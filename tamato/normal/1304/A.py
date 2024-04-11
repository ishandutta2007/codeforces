def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        x, y, a, b = map(int, input().split())
        if (y-x)%(a+b):
            print(-1)
            continue
        print((y-x) // (a+b))


if __name__ == '__main__':
    main()