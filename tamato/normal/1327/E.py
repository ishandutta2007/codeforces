def main():
    import sys
    input = sys.stdin.readline

    N = int(input())
    mod = 998244353

    ten = [0] * (N+1)
    for i in range(1, N+1):
        ten[i] = pow(10, i, mod)

    ans = [0] * (N+1)
    S = 0
    for i in range(1, N+1):
        a = ((ten[i] * i)%mod - ((ten[i-1] * (i-1))%mod + S)%mod)%mod
        ans[i] = a
        S = (S + a)%mod
    ans.reverse()
    print(*ans[:-1])


if __name__ == '__main__':
    main()