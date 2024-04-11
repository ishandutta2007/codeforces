import sys
range = xrange
input = raw_input

t = int(input())

for _ in range(t):
    n = int(input())
    grid = [ input(), input() ]

    r = 0
    ok = True
    for c in range(n):
        if grid[r][c] > '2':
            r ^= 1
            if grid[r][c] <= '2':
                ok = False
                break
    if r == 0:
        ok = False

    print 'YES' if ok else 'NO'