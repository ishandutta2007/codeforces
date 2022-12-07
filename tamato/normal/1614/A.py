mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, L, R, K = map(int, input().split())
        A = list(map(int, input().split()))
        A.sort()
        ans = 0
        for a in A:
            if L <= a <= R:
                if K >= a:
                    ans += 1
                    K -= a

        print(ans)


if __name__ == '__main__':
    main()