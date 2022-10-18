import sys
input = sys.stdin.readline
import math

sys.setrecursionlimit(200020)

import threading
threading.stack_size(2 ** 27)

def main():
    for _ in range(int(input())):
        input()
        n, k = map(int, input().split())
        x, y = map(int, input().split())
        z = list(map(int, input().split()))
        g = [[] for i in range(n)]
        x -= 1
        y -= 1
        for i in range(n - 1):
            a, b = map(int, input().split())
            a -= 1
            b -= 1
            g[a].append(b)
            g[b].append(a)
        a = [False] * n
        for i in z:
            a[i - 1] = True
        depth = [0] * n
        found = [False] * n
        def Dfs(v, p):
            if a[v] or y == v:
                found[v] = True
            for to in g[v]:
                if to == p:
                    continue
                depth[to] = depth[v] + 1
                Dfs(to, v)
                if found[to]:
                    found[v] = True
        Dfs(x, -1)
        ans = 0
        for i in range(n):
            if i != x and found[i]:
                ans += 2
        ans -= depth[y]
        print(ans)

threading.Thread(target=main).start()