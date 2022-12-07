mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N, x = map(int, input().split())
        A = list(map(int, input().split()))

        A.sort()
        used = {}
        ans = N
        for i, a in enumerate(A):
            if a in used:
                if used[a] > 0:
                    used[a] -= 1
                    ans -= 2
                    continue
            if a * x not in used:
                used[a * x] = 0
            used[a * x] += 1
        print(ans)


if __name__ == '__main__':
    main()