n = input()
last = 0
for _ in xrange(n):
    a, b = map(int, raw_input().split())
    for i in xrange(1000001):
        if a + b * i > last:
            last = a + b * i
            break
print last