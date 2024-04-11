import sys, os

if 'READ_FILE' in os.environ:
    inp = open("x.in", "r")
else:
    inp = sys.stdin

m = 200001
n = int(inp.readline())
a = list(map(int, inp.readline().split(' ')))
p = [0] * m
i = 2
while i * i < m:
    if p[i] == 0:
        j = i * i
        while j < m:
            p[j] = i
            j += i
    i += 1
for i in range(m):
    if p[i] == 0:
        p[i] = i

class Div:
    def __init__(self):
        self.used = 0
        self.c1 = 2 ** 31
        self.c2 = 2 ** 31

    def update(self, cnt):
        self.used += 1
        if cnt < self.c1:
            self.c2 = self.c1
            self.c1 = cnt
        elif cnt < self.c2:
            self.c2 = cnt

divs = [Div() for i in range(m)]

for x in a:
    while x != 1:
        d = p[x]
        cnt = 0
        while x % d == 0:
            x = x // d
            cnt += 1
        divs[d].update(cnt)

res = 1
for x in range(len(divs)):
    d = divs[x]

    if d.used == n:
        cnt = d.c2
    elif d.used == n-1:
        cnt = d.c1
    else:
        continue

    res *= x**cnt
print(res)