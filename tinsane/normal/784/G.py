import collections as col
import itertools as its
import sys
import operator
from bisect import bisect_left, bisect_right
from copy import copy, deepcopy


class Solver:
    def __init__(self):
        pass
    
    def solve(self):
        expr = input()
        v = eval(expr)
        res = str(v)
        for c in res:
            print('>', end='')
            print('+' * ord(c) + '.', end='')
        print('')


if __name__ == '__main__':
    s = Solver()
    s.solve()