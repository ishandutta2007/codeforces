mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))

        ans = 0
        m = min(A)
        for a in A:
            if a != m:
                ans += 1
        print(ans)


if __name__ == '__main__':
    main()