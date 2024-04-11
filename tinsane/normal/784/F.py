import collections as col
import itertools as its
import sys
import operator
from bisect import bisect_left, bisect_right
from copy import copy, deepcopy
from time import sleep


class Solver:
    def __init__(self):
        pass
    
    def solve(self):
        a = list(map(int, input().split()))
        n = a[0]
        a = a[1:]
        c = 0
        for i in range(10**7):
            c += i
        print(' '.join(map(str, sorted(a))))


if __name__ == '__main__':
    s = Solver()
    s.solve()