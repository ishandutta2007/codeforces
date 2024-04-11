import sys
n = int(raw_input())
lhs = []
rhs = []
def solve(a, b):
    ret = [a, b]
    while len(ret) < n:
        if lhs[ret[-2]] == ret[-1]:
            ret.append(rhs[ret[-2]])
        elif rhs[ret[-2]] == ret[-1]:
            ret.append(lhs[ret[-2]])
        else:
            return
    print " ".join([str(x+1) for x in ret])
    sys.exit(0)


for _ in xrange(n):
    a, b = (int(x) for x in raw_input().split())
    lhs.append(a-1)
    rhs.append(b-1)

solve(0, lhs[0])
solve(0, rhs[0])