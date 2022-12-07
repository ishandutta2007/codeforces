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

    N = int(input())
    prime = PrimeDecomposition(N)
    ans = []
    for p in prime:
        for _ in range(prime[p]):
            ans.append(p)
    ans.sort()
    print(''.join(map(str, ans)))


if __name__ == '__main__':
    main()