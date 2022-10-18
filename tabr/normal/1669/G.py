import sys
input = sys.stdin.readline
import math

for _ in range(int(input())):
    h, w = map(int, input().split())
    s = [['o'] * w for _ in range(h)]
    for i in range(h):
        t = input()
        for j in range(w):
            s[i][j] = t[j]
    for j in range(w):
        que = []
        que_index = 0
        for i in reversed(range(h)):
            if s[i][j] == '.':
                que.append(i)
            elif s[i][j] == 'o':
                que_index = len(que)
            elif que_index < len(que):
                s[que[que_index]][j] = '*'
                s[i][j] = '.'
                que_index += 1
                que.append(i)
    for i in range(h):
        print(*s[i], sep = "")