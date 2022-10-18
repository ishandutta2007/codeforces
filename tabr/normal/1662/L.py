class SegmentTree:
    def __init__(self, init_val, segfunc, ide_ele):
        n = len(init_val)
        self.segfunc = segfunc
        self.ide_ele = ide_ele
        self.num = 1 << (n - 1).bit_length()
        self.tree = [ide_ele] * 2 * self.num
        self.size = n
        for i in range(n):
            self.tree[self.num + i] = init_val[i]
        for i in range(self.num - 1, 0, -1):
            self.tree[i] = self.segfunc(self.tree[2 * i], self.tree[2 * i + 1])

    def update(self, k, x):
        k += self.num
        self.tree[k] = self.segfunc(self.tree[k],x)
        while k > 1:
            k >>= 1
            self.tree[k] = self.segfunc(self.tree[2*k], self.tree[2*k+1])

    def query(self, l, r):
        if r==self.size:
            r = self.num

        res = self.ide_ele

        l += self.num
        r += self.num
        right = []
        while l < r:
            if l & 1:
                res = self.segfunc(res, self.tree[l])
                l += 1
            if r & 1:
                right.append(self.tree[r-1])
            l >>= 1
            r >>= 1

        for e in right[::-1]:
            res = self.segfunc(res,e)
        return res

import sys,random,bisect
from collections import deque,defaultdict
from heapq import heapify,heappop,heappush
from itertools import permutations
from math import log,gcd

input = lambda :sys.stdin.buffer.readline()
mi = lambda :map(int,input().split())
li = lambda :list(mi())


if 1:
    N,V = mi()
    T = li()
    X = li()
    item = [(V*t,x) for t,x in zip(T,X)]
else:
    N = int(input())
    item = [tuple(mi()) for i in range(N)]

item.sort(key=lambda x:x[0]-x[1])

val = set([x[0]+x[1] for x in item]+[0])
comp = {e:i for i,e in enumerate(sorted(val))}
n = len(comp)

dp = SegmentTree([-10**17]*n,max,-10**17)
dp.update(comp[0],0)
if 1:
    for t,x in item:
        if t-x < 0:
            continue
        tmp = dp.query(0,comp[t+x]+1) + 1
        dp.update(comp[t+x],tmp)
else:
    for t,x,v in item:
        if t-x < 0:
            continue
        tmp = dp.query(0,comp[t+x]+1) + v
        dp.update(comp[t+x],tmp)

print(dp.query(0,n))