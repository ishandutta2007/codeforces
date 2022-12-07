mod = 1000000007
eps = 10**-9


def main():
    import sys
    input = sys.stdin.readline

    for _ in range(int(input())):
        N = int(input())
        P = list(map(int, input().split()))

        ma = [0] * N
        ma[0] = P[0]
        for i in range(1, N):
            ma[i] = max(ma[i-1], P[i])

        ans = []
        tmp = []
        m = N
        for i in range(N-1, -1, -1):
            p = P[i]
            tmp.append(p)
            if p == m:
                tmp.reverse()
                ans.extend(tmp)
                tmp = []
                m = ma[i-1]
        print(*ans)


if __name__ == '__main__':
    main()