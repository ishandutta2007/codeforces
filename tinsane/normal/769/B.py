import collections as col
import itertools as its
import operator


class Solver:
    def solve(self):
        n = int(input())
        a = list(map(int, input().split()))
        for i in range(len(a)):
            a[i] = [a[i], i + 1]
        a[0][0] += 1000
        a = sorted(a)[::-1]
        a[0][0] -= 1000
        ans = []
        it = 1
        for i in range(len(a)):
            if i == it:
                print(-1)
                return
            cnt, st = a[i]
            while it != n and cnt > 0:
                ans.append((st, a[it][1]))
                cnt -= 1
                it += 1
        print(n - 1)
        for p in ans:
            print(' '.join(map(str, p)))


if __name__ == '__main__':
    s = Solver()
    s.solve()