def main():
    import sys
    from math import gcd, sqrt
    input = sys.stdin.readline

    def f(n, d):
        return n // d

    def prime(n):
        ret = {}
        for d in range(2, int(sqrt(n))+1):
            while n % d == 0:
                ret[d] = 1
                n //= d
        if n > 1:
            ret[n] = 1
        return ret

    for _ in range(int(input())):
        a, m = map(int, input().split())
        k = gcd(a, m)
        p = a // k
        q = m // k
        ans = q
        pr = list(prime(q))
        np = len(pr)
        for i in range(1, 1<<np):
            sign = 0
            d = 1
            for j in range(np):
                if i >> j & 1:
                    sign ^= 1
                    d *= pr[j]
            sign = (-1)**sign
            ans += (f(p+q-1, d) - f(p-1, d))*sign
        print(ans)


if __name__ == '__main__':
    main()