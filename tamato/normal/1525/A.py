mod = 1000000007
eps = 10**-9


def main():
    import sys
    from math import gcd
    input = sys.stdin.readline

    for _ in range(int(input())):
        a = int(input())
        g = gcd(a, 100 - a)
        print(100 // g)


if __name__ == '__main__':
    main()