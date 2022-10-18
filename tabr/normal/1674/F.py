import sys
input = sys.stdin.readline
import math

from typing import List

class fenwick:
    n: int = 1
    fenw: List[int] = []
    
    def __init__(self, n_: int):
        self.n = n_
        self.fenw = [0] * self.n
    
    def add_value(self, x: int, v: int):
        while x < self.n:
            self.fenw[x] += v
            x = x | (x + 1)
    
    def get_value(self, x: int) -> int:
        v = 0
        while x >= 0:
            v += self.fenw[x]
            x = (x & (x + 1)) - 1
        return v

for _ in range(1):
    h, w, q = map(int, input().split())
    f = fenwick(h * w)
    a = [0] * (h * w)
    cnt = 0
    for i in range(h):
        s = input()
        for j in range(w):
            if s[j] == '*':
                f.add_value(j * h + i, 1)
                a[j * h + i] = 1
                cnt += 1
    for i in range(q):
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        z = y * h + x
        if a[z] == 1:
            f.add_value(z, -1)
            a[z] = 0
            cnt -= 1
        else:
            f.add_value(z, 1)
            a[z] = 1
            cnt += 1
        print(cnt - f.get_value(cnt - 1))