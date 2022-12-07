mod = 1000000007
eps = 10**-9


def main():
    import sys
    from collections import Counter
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        A = list(map(int, input().split()))
        C = Counter(A)

        ans = 0
        for i in range(101):
            if C[i] == 0:
                ans += i
                break
            else:
                C[i] -= 1

        for i in range(101):
            if C[i] == 0:
                ans += i
                break
        print(ans)


if __name__ == '__main__':
    main()