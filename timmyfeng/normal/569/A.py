t, s, q = map(int, raw_input().split())
a = 0
while s < t:
    s *= q
    a += 1
print a