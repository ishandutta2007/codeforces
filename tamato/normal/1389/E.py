mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.readline

    for _ in range(int(input())):
        m, d, w = map(int, input().split())
        g = gcd(w, d-1)
        v = w // g
        md = min(m, d)
        n = md // v
        a = md % v
        b = v - a
        ans = ((n+1) * n // 2) * a + (n * (n-1) // 2) * b
        print(ans)


if __name__ == '__main__':
    main()