x = int(raw_input())
h, m = (int(y) for y in raw_input().split())
ret = 0
while '7' not in str(h) and '7' not in str(m):
    m -= x
    while m < 0:
        m += 60
        h -= 1
        if h < 0:
            h += 24
    ret += 1
print ret