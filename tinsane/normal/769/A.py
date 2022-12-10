import collections as col
import itertools as its
import operator


class Solver:
    def solve(self):
        n = int(input())
        a = list(map(int, input().split()))
        print((max(a) + min(a)) // 2)


if __name__ == '__main__':
    s = Solver()
    s.solve()