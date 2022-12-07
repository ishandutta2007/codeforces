def main():
    import sys
    input = sys.stdin.readline

    q = int(input())
    for _ in range(q):
        c, m, x = map(int, input().split())
        print(min(c, m, (c+m+x)//3))


if __name__ == '__main__':
    main()