def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().split()))

        s = 0
        ans = 0
        for a in A:
            if a == 0:
                ans += 1
                s += 1
            else:
                s += a
        if s == 0:
            ans += 1
        print(ans)


if __name__ == '__main__':
    main()