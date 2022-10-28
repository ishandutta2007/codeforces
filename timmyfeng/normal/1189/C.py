n = input()
a = [0] + map(int, raw_input().split())

for i in range(n):
    a[i + 1] += a[i]

q = input()
for i in range(q):
    l, r = map(int, raw_input().split())
    print((a[r] - a[l - 1]) / 10)