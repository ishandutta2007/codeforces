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
        s = ''
        for i in range(k):
            s += chr(ord('a') + i)
        now = 0
        while len(s) < n:
            s += chr(ord('a') + now)
            now = not now
        print(s)


if __name__ == '__main__':
    s = Solver()
    s.solve()