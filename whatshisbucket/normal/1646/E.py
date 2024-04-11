import sys
I=lambda:[*map(int,sys.stdin.readline().split())]

n, m = I()
tot = n * m

count = [0]
s = set()
for i in range(len(bin(n)) - 3):
    for j in range(1, m + 1):
        s.add(j * (i + 1))
    count.append(len(s))

new = [0] * (n + 1)
tot = 1
for i in range(2, n + 1):
    if new[i] == 0:
        curr = i
        cnt = 1
        vals = [i]
        while curr * i <= n:
            curr *= i
            vals.append(curr)
            cnt += 1
        tot += count[cnt]
        for guy in vals:
            new[guy] = 1
print(tot)