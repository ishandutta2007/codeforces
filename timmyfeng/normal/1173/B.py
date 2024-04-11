n = input()
m = n / 2 + 1

print m
for i in range(1, n + 1):
    print max(1, i - m + 1), min(m, i)