import heapq

n = int(input())
a = list(map(int, input().split()))

pq = [0]
ans = 0
tot = 0

for x in a:
    if tot + x >= 0:
        ans += 1
        tot += x
        heapq.heappush(pq, x)
    elif x >= pq[0]:
        tot += x - pq[0]
        heapq.heappop(pq)
        heapq.heappush(pq, x)

print(ans)