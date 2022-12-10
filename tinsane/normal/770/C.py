import collections as col
import itertools as its
import sys
import operator
from copy import copy, deepcopy


class Solver:
    def __init__(self):
        pass
    
    def solve(self):
        n, k = map(int, input().split())
        q = list(map(lambda x: int(x) - 1, input().split()))
        used = [False] * n
        for e in q:
            used[e] = True
        edges = [[] for _ in range(n)]
        redges = [[] for _ in range(n)]
        for i in range(n):
            l = list(map(lambda x: int(x) - 1, input().split()))[1:]
            edges[i] = l
            for e in l:
                redges[e].append(i)
        degs = [len(edges[i]) for i in range(n)]
        d = 0
        while d < len(q):
            v = q[d]
            d += 1
            for e in edges[v]:
                if not used[e]:
                    used[e] = True
                    q.append(e)
        q = q[::-1]
        nq = []
        for v in q:
            if degs[v] == 0:
                nq.append(v)
        d = 0
        while d < len(nq):
            v = nq[d]
            d += 1
            for e in redges[v]:
                if not used[e]:
                    continue
                degs[e] -= 1
                if degs[e] == 0:
                    nq.append(e)
        #print(nq)
        if len(q) != len(nq):
            print(-1)
            return
        print(len(nq))
        print(' '.join(map(lambda x: str(x + 1), nq)))
        


if __name__ == '__main__':
    s = Solver()
    s.solve()