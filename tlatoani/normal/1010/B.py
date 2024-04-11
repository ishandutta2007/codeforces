m, n = map(int, input().split())
pattern = []
for _ in range(n):
    print(m)
    res = int(input())
    if res == 0:
        quit()
    pattern.append(-res)
lower = 1
upper = m - 1
for i in range(30):
    mid = (lower + upper) >> 1
    print(mid)
    res = int(input()) * pattern[i % n]
    if res == 0:
        quit()
    elif res < 0:
        upper = mid - 1
    else:
        lower = mid + 1