mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    def PrimeDecomposition(N):
        ret = {}
        n = int(N ** 0.5)
        for d in range(2, n + 1):
            while N % d == 0:
                if d not in ret:
                    ret[d] = 1
                else:
                    ret[d] += 1
                N //= d
            if N == 1:
                break
        if N != 1:
            ret[N] = 1
        return ret

    for _ in range(int(input())):
        p, q = map(int, input().split())
        if p % q != 0:
            print(p)
            continue
        prime = PrimeDecomposition(q)
        C = {}
        mi = p
        for pr in prime:
            C = 0
            tmp = p
            while tmp % pr == 0:
                C += 1
                tmp //= pr
            mi = min(mi, pr ** (C - prime[pr] + 1))
        print(p // mi)


if __name__ == '__main__':
    main()