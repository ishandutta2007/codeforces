ret = -(10**9)
n = int(raw_input())
l = [int(x) for x in raw_input().split()]
for x in l:
    y = 0
    while y * y < x:
        y += 1
    if y * y != x:
        ret = max(ret, x)
print ret