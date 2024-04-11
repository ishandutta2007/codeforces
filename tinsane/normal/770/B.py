import collections as col
import itertools as its
import sys
import operator
from copy import copy, deepcopy


class Solver:
    def __init__(self):
        pass
    
    def solve(self):
        xs = input()
        pxs = xs
        xs = list(map(int, xs))
        bpos = -1
        for i in range(1, len(xs)):
            if xs[i] != 9:
                bpos = i
                break
        if bpos != -1:
            xs[bpos-1] -= 1
            for i in range(bpos, len(xs)):
                xs[i] = 9
        xs = ''.join(map(str, xs))
        if sum(map(int, pxs)) >= sum(map(int, xs)):
            xs = pxs
        print(int(xs))


if __name__ == '__main__':
    s = Solver()
    s.solve()