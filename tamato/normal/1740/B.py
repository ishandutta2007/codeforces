mod = 998244353


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        ans = 0
        x_max = 0
        for _ in range(N):
            x, y = map(int, input().split())
            if x < y:
                x, y = y, x
            x_max = max(x_max, x)
            ans += y * 2
        ans += x_max * 2
        print(ans)


if __name__ == '__main__':
    main()