n = input()
a = map(int, raw_input().split())

pos1 = [-1] * (n + 1)
pos2 = [-1] * (n + 1)
for i in range(2 * n):
    if pos1[a[i]] == -1:
        pos1[a[i]] = i
    else:
        pos2[a[i]] = i

pos1[0], pos2[0], ans = 0, 0, 0
for i in range(n):
    ans += abs(pos1[i + 1] - pos1[i]) + abs(pos2[i + 1] - pos2[i])

print(ans)