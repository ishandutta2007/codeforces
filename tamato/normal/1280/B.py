import sys

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    h, w = map(int, input().split())
    grid = []
    for _ in range(h):
        line = input().rstrip('\n')
        tmp = [line[i] == 'A' for i in range(w)]
        grid.append(tmp)

    ok = 0
    all_A = 1
    for i in range(h):
        for j in range(w):
            if grid[i][j]:
                ok = 1
            else:
                all_A = 0
    if not ok:
        print('MORTAL')
        continue
    if all_A:
        print(0)
        continue

    all_True = 1
    for i in range(w):
        if not grid[0][i]:
            all_True = 0
            break
    if all_True:
        print(1)
        continue

    all_True = 1
    for i in range(w):
        if not grid[-1][i]:
            all_True = 0
            break
    if all_True:
        print(1)
        continue

    all_True = 1
    for i in range(h):
        if not grid[i][0]:
            all_True = 0
            break
    if all_True:
        print(1)
        continue

    all_True = 1
    for i in range(h):
        if not grid[i][-1]:
            all_True = 0
            break
    if all_True:
        print(1)
        continue

    if grid[0][0] | grid[0][-1] | grid[-1][0] | grid[-1][-1]:
        print(2)
        continue

    flg = 0
    for i in range(1, h-1):
        if sum(grid[i]) == w:
            flg = 1
            break
    for i in range(1, w-1):
        ok = 1
        for k in range(h):
            if not grid[k][i]:
                ok = 0
                break
        if ok:
            flg = 1
            break
    if flg:
        print(2)
        continue

    any_True = 0
    for i in range(w):
        if grid[0][i]:
            any_True = 1
            break
        if grid[-1][i]:
            any_True = 1
            break
    for i in range(h):
        if grid[i][0]:
            any_True = 1
            break
        if grid[i][-1]:
            any_True = 1
            break
    if any_True:
        print(3)
        continue

    print(4)