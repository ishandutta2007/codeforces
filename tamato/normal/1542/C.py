mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        ans = 0
        k = 1
        NN = N
        for d in range(2, 100):
            k = (k * d) // gcd(k, d)
            M = N // k
            ans = (ans + ((NN - M) * d)%mod)%mod
            NN = M
            if NN == 0:
                break
        print(ans)


if __name__ == '__main__':
    main()