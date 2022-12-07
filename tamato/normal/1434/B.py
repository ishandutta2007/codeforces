mod = 1000000007
eps = 10**-9


def main():
    import sys
    from heapq import heappush, heappop
    input = sys.stdin.readline

    N = int(input())
    ev = []
    for _ in range(2*N):
        line = list(input().split())
        ev.append(line)
    ev.reverse()
    pq = []
    ans = []
    for line in ev:
        if len(line) == 1:
            if not pq:
                print("NO")
                exit()
            ans.append(heappop(pq))
        else:
            x = int(line[1])
            if pq:
                if x > pq[0]:
                    print("NO")
                    exit()
                else:
                    heappush(pq, x)
            else:
                heappush(pq, x)
    ans.reverse()
    print("YES")
    print(*ans)


if __name__ == '__main__':
    main()