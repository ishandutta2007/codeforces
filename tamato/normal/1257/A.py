def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        n, x, a, b = map(int, input().split())
        if a > b:
            a, b = b, a
        print(min(n-1, b-a+x))


if __name__ == '__main__':
    main()