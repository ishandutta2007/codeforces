def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    for _ in range(N):
        c, s = map(int, input().split())
        d = s//c
        m = s%c
        print((d+1)**2 * m + d**2 * (c - m))


if __name__ == '__main__':
    main()