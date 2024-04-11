from collections import Counter
import sys
input = sys.stdin.readline


class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)

    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s

    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i


q = int(input())
for _ in range(q):
    n = int(input())
    s = input()
    t = input()
    if Counter(s) != Counter(t):
        print('NO')
        continue
    elif Counter(s).most_common()[0][1] > 1:
        print('YES')
        continue
    s_list = [ord(s[i]) for i in range(n)]
    t_list = [ord(t[i]) for i in range(n)]

    bit_s = Bit(150)
    inv_s = 0
    for i in range(n-1, -1, -1):
        inv_s += bit_s.sum(s_list[i])
        bit_s.add(s_list[i], 1)

    bit_t = Bit(150)
    inv_t = 0
    for i in range(n - 1, -1, -1):
        inv_t += bit_t.sum(t_list[i])
        bit_t.add(t_list[i], 1)

    if (inv_s - inv_t) % 2 == 0:
        print('YES')
    else:
        print('NO')