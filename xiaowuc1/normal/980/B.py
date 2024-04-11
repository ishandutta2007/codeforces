n, k = (int(x) for x in raw_input().split())
print "YES"
print "." * n
ret = ['.'] * n
amt = k
lhs = 1
rhs = n-2
while amt:
    if lhs == rhs:
        ret[lhs] = '#'
        amt -= 1
        break
    if amt >= 2:
        ret[lhs] = '#'
        ret[rhs] = '#'
        lhs += 1
        rhs -= 1
        amt -= 2
    else:
        ret[n/2] = '#'
        amt = 0

print "".join(ret)

ret = ['.'] * n
lhs = 1
rhs = n-2
while amt:
    if lhs == rhs:
        ret[lhs] = '#'
        amt -= 1
        break
    if amt >= 2:
        ret[lhs] = '#'
        ret[rhs] = '#'
        lhs += 1
        rhs -= 1
        amt -= 2
    else:
        ret[n/2] = '#'
        amt = 0

print "".join(ret)
print "." * n