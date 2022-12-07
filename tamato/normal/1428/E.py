mod = 1000000007
eps = 10**-9


def main():
    import sys
    from heapq import heappop, heappush
    input = sys.stdin.readline

    def calc(a, d):
        return ((a // d + 1) ** 2) * (a % d) + ((a // d) ** 2) * (d - a%d)

    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    ans = 0
    pq = []
    for a in A:
        ans += a * a
        if a > 1:
            heappush(pq, (calc(a, 2) - calc(a, 1), a, 2))

    for _ in range(K - N):
        g, a, d = heappop(pq)
        ans += g
        if a > d:
            heappush(pq, (calc(a, d+1) - calc(a, d), a, d+1))
    print(ans)


if __name__ == '__main__':
    main()