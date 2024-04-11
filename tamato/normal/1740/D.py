mod = 998244353


def main():
    import sys
    from heapq import heappop, heappush
    input = sys.stdin.readline

    for _ in range(int(input())):
        H, W, K = map(int, input().split())
        P = list(map(int, input().split()))

        D = H * W - 4
        pq = []
        L = 0
        x = K
        ok = 1
        for p in P:
            heappush(pq, -p)
            L += 1
            while pq:
                if -pq[0] == x:
                    heappop(pq)
                    x -= 1
                    L -= 1
                else:
                    break
            if L > D:
                ok = 0
                break
        if ok:
            print("YA")
        else:
            print("TIDAK")


if __name__ == '__main__':
    main()