n, m, k = tuple(map(int, input().split(' ')))
marks = [0 for i in range(m)]
for i in range(n):
    s = input()
    for j in range(m):
        if s[j] == 'Y':
            marks[j] += 1
res = 0
for mark in marks:
    if mark >= k:
        res += 1
print(res)
"""
a kitten
"""