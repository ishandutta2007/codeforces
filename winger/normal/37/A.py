n = int(raw_input())
ls = list(map(int, raw_input().split()))

count, maxh = 0, 0
ls.sort()
last = -1
curh = 0
for l in ls:
    if l == last:
        curh += 1
    else:
        maxh = max(maxh, curh)
        count += 1
        last = l
        curh = 1
maxh = max(maxh, curh)
print maxh, count