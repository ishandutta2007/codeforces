def main():
    import sys
    from heapq import heappop, heappush
    input = sys.stdin.readline

    N = int(input())
    pq = []
    seen = [0] * (N+1)
    for i in range(N//2, 1, -1):
        for j in range(2, N):
            ii = i*j
            if ii > N:
                break
            if not seen[ii]:
                seen[ii] = 1
                heappush(pq, -i)
    ans = [1] * (N-1)
    i = -1
    while pq:
        ans[i] = -heappop(pq)
        i -= 1
    print(*ans)


if __name__ == '__main__':
    main()