def main():
    import sys
    from fractions import gcd
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        r, b, k = map(int, input().split())
        if r > b:
            r, b = b, r
        g = gcd(r, b)
        r //= g
        b //= g
        if (b - 2) // r + 1 >= k:
            print('REBEL')
        else:
            print('OBEY')

            
if __name__ == '__main__':
    main()