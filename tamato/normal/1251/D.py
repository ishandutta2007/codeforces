def main():
    import sys
    import heapq
    input = sys.stdin.readline

    t = int(input())
    for _ in range(t):
        N, S = map(int, input().split())
        cost = []
        m = []
        for _ in range(N):
            l, r = map(int, input().split())
            cost.append((l, r))
            m.append(l)
        m.sort()
        ok = m[N//2]
        ng = S+1
        mid = (ok+ng)//2
        while ng - ok > 1:
            big = []
            small = []
            for l, r in cost:
                if r >= mid:
                    big.append(-l)
                else:
                    small.append(l)
            if len(big) < N//2 + 1:
                ng = mid
                mid = (ok+ng)//2
                continue
            heapq.heapify(big)
            C = 0
            for i in range(N//2 + 1):
                C += max(-heapq.heappop(big), mid)
            for l in big:
                small.append(-l)
            C += sum(small)
            if C <= S:
                ok = mid
            else:
                ng = mid
            mid = (ok+ng)//2

        print(ok)


if __name__ == '__main__':
    main()