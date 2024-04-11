c, v0, v1, a, l = (int(x) for x in raw_input().split())
ret = 0
total = 0
while total < c:
    amt_read = min(v1, v0 + ret * a)
    ret += 1
    if ret > 1:
        amt_read -= l
    total += amt_read
print ret