import sys
from collections import defaultdict
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    N = int(input())
    w00 = 0
    w11 = 0
    w01 = defaultdict(int)
    w10 = defaultdict(int)
    for i in range(1, N+1):
        w = input().rstrip('\n')
        if w[0] == w[-1] == '0':
            w00 = 1
        elif w[0] == w[-1] == '1':
            w11 = 1
        elif w[0] == '0':
            w_rev = w[::-1]
            w10[w_rev] = -1
            if w01[w] == 0:
                w01[w] = i
        else:
            w_rev = w[::-1]
            w01[w_rev] = -1
            if w10[w] == 0:
                w10[w] = i
    if w00 == w11 == 1:
        if len(w01) == len(w10) == 0:
            print(-1)
            continue
    ans = 0
    i01 = []
    i10 = []
    for i in w01.values():
        if i > 0:
            i01.append(i)
    for i in w10.values():
        if i > 0:
            i10.append(i)
    if len(i01) > len(i10):
        ans = i01[:(len(i01) - len(i10))//2]
    else:
        ans = i10[:(len(i10) - len(i01)) // 2]
    print(len(ans))
    print(*ans)