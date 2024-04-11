def solve():
    raw_input()
    l = [int(x) for x in raw_input().split()]
    l.append(0)
    ret = 0
    i = 1
    while i + 1 < len(l):
        if l[i] - l[i+1] == 1:
            i += 2
        else:
            i += 1
            ret += 1
    print ret

t = int(raw_input())
for _ in xrange(t):
    solve()