def main():
    import sys
    input = sys.stdin.readline

    N, M, L, R = map(int, input().split())
    mod = 998244353

    ans = pow((R-L+1)%mod, N*M, mod)
    if N&1 and M&1:
        print(ans)
    else:
        if (R-L+1)&1:
            print(((ans + 1) * pow(2, mod - 2, mod)) % mod)
        else:
            print((ans * pow(2, mod-2, mod))%mod)


if __name__ == '__main__':
    main()