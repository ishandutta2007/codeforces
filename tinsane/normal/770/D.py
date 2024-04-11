import collections as col
import itertools as its
import sys
import operator
from copy import copy, deepcopy


class Solver:
    def __init__(self):
        pass
    
    def solve(self):
        n = int(input())
        psp = input()
        m = 0
        st = []
        pair = [0] * n
        for i in range(n):
            if psp[i] == '[':
                st.append(i)
                m = max(m, len(st))
            else:
                p = st.pop()
                pair[p] = i
                pair[i] = p
        tres = [''] * (m * 2 + 1)
        now = m
        for i in range(n):
            if psp[i] == '[':
                tres[m] += '|'
                for j in range(1, now):
                    tres[m + j] += '|'
                    tres[m - j] += '|'
                tres[m + now] += '+-'
                tres[m - now] += '+-'
                l = len(tres[m + now])
                for j in range(2 * m + 1):
                    while len(tres[j]) < l:
                        tres[j] += ' '
                now -= 1
            else:
                now += 1
                tres[m] += ' |'
                for j in range(1, now):
                    tres[m + j] += ' |'
                    tres[m - j] += ' |'
                tres[m + now] += '-+'
                tres[m - now] += '-+'
                l = len(tres[m + now])
                for j in range(2 * m + 1):
                    while len(tres[j]) < l:
                        tres[j] += ' '
        #for i in range(2 * m + 1):
        #    print(''.join(tres[i]))
        res = [[' '] for _ in range(2 * m + 1)]
        for i in range(len(tres[0])):
            inter = False
            skip = False
            for j in range(2 * m + 1):
                if tres[j][i] != ' ' and res[j][-1] != ' ':
                    inter = True
                    if tres[j][i] == '-' and res[j][-1] == '-':
                        skip = True
            if inter:
                for j in range(2 * m + 1):
                    res[j].append(' ')
            #print('skip = {}'.format(skip))
            if skip:
                for j in range(2 * m + 1):
                    res[j].append(' ')
            for j in range(2 * m + 1):
                if tres[j][i] != ' ':
                    res[j][-1] = tres[j][i]
        for i in range(2 * m + 1):
            print(''.join(res[i]))


if __name__ == '__main__':
    s = Solver()
    s.solve()