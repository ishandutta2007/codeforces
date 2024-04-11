n, a, b, T = map(int, input().split())
s = input()

prefsum = [0] * n
suffsum = [0] * n

for i in range(n):
    prefsum[i] = 1 if s[i] == 'h' else b + 1
    if i > 0:
        prefsum[i] += a + prefsum[i - 1]

suffsum[-1] = a
for i in range(n - 1, -1, -1):
    suffsum[i] += 1 if s[i] == 'h' else b + 1
    if i + 1 < n:
        suffsum[i] += a + suffsum[i + 1]

res = 0

# go right and come back left
l = 1
for r in range(n):
    l = max(l, r + 1)
    while l < n and suffsum[l] + r * a + prefsum[r] > T:
        l += 1
    if prefsum[r] > T:
        break
    res = max(res, r + 1 + n - l)

# go left and come back right
l = 1
for r in range(n):
    l = max(l, r + 1)
    while l < n and suffsum[l] + (n - l) * a + prefsum[r] > T:
        l += 1
    if prefsum[r] > T:
        break
    res = max(res, r + 1 + n - l)

# go in a single direction
for r in range(n):
    # right
    if prefsum[r] <= T:
        res = max(res, r + 1)
    # left
    if r > 0 and suffsum[r] + prefsum[0] <= T:
        res = max(res, n - r + 1)

print(res)