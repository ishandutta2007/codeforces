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
        a = int(input())
        b = int(input())
        c = int(input())
        d = int(input())
        l11 = a ^ b
        l12 = c | d
        l13 = b & c
        l14 = a ^ d
        l21 = l11 & l12
        l22 = l13 | l14
        print(l21 ^ l22)


if __name__ == '__main__':
    s = Solver()
    s.solve()