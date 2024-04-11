def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        d, mod = map(int, input().split())
        LV = d.bit_length()
        ans = 0
        for lv in range(1, LV):
            new = ((ans+1) * (1<<(lv-1)))%mod
            ans += new
            ans %= mod
        n = d - (1 << (LV-1)) + 1
        new = ((ans + 1) * n) % mod
        ans += new
        ans %= mod
        print(ans)


if __name__ == '__main__':
    main()