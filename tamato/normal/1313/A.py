def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        ans = 0
        a, b, c = map(int, input().split())

        if a > 0:
            ans += 1
            a -= 1
        if b > 0:
            ans += 1
            b -= 1
        if c > 0:
            ans += 1
            c -= 1
        a, b, c = sorted([a, b, c])
        if a >= 3:
            ans += 4
        elif a == 2:
            ans += 3
        elif a == 1:
            if c == 1:
                ans += 1
            else:
                ans += 2
        elif a == 0:
            if b > 0 and c > 0:
                ans += 1
        print(ans)


if __name__ == '__main__':
    main()