import sys
input = sys.stdin.readline
import math

sys.setrecursionlimit(10000)
import threading
threading.stack_size(2 ** 27)

def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        s = input()
        g = [[] for i in range(n)]
        for i in range(n - 1):
            g[a[i] - 1].append(i + 1)
        b = [0] * n
        def Dfs(v):
            if s[v] == 'B':
                b[v] += 1
            else:
                b[v] -= 1
            for to in g[v]:
                Dfs(to)
                b[v] += b[to]
        Dfs(0)
        ans = 0
        for i in b:
            if i == 0:
                ans += 1
        print(ans)
threading.Thread(target=main).start()