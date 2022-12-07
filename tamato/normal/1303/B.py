def main():
    import sys
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        n, g, b = map(int, input().split())

        bad_lim = n // 2
        d = bad_lim // b
        n0 = (g+b) * d + g + bad_lim%b

        if n0 >= n:
            print(n)
        else:
            ans = n0
            ans += b - bad_lim%b
            dd = (n - n0) // g
            ans += (g+b) * dd
            if (n-n0)%g:
                ans += (n-n0)%g
            else:
                ans -= b
            print(ans)


if __name__ == '__main__':
    main()