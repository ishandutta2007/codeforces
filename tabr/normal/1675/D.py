import sys
input = sys.stdin.readline
import math

sys.setrecursionlimit(200020)

import threading
threading.stack_size(2 ** 27)

def main():
    for _ in range(int(input())):
        n = int(input())
        p = list(map(int, input().split()))
        g = [[] for i in range(n)]
        root = -1
        for i in range(n):
            p[i] -= 1
            if p[i] != i:
                g[p[i]].append(i)
            else:
                root = i
        ans = [[]]
        def dfs(v, index):
            ans[index].append(v)
            for to in g[v]:
                if to == g[v][0]:
                    dfs(to, index)
                else:
                    ans.append([])
                    dfs(to, len(ans) - 1)
        dfs(root, 0)
        print(len(ans))
        for a in ans:
            print(len(a))
            for i in range(len(a)):
                a[i] += 1
            print(*a)
        print()

threading.Thread(target=main).start()