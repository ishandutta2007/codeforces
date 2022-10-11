a, b = (int(x) for x in raw_input().split())
if a <= b:
    print a
else:
    ret = b
    lhs = 1
    rhs = int(1e18)
    while lhs < rhs:
        mid = (lhs+rhs)/2
        if mid*(mid+1)/2 >= a-b:
            rhs = mid
        else:
            lhs = mid+1
    print ret + lhs