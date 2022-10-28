n = input()
a = sorted(map(int, raw_input().split()))

inf = n * 10 ** 9
ans, i = inf, 1

while True:
    res = 0
    for j in range(n):
        res += abs(i ** j - a[j])
    if res > inf:
        break
    ans = min(ans, res)
    i += 1

print ans