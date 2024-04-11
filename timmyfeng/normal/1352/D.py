import sys
range = xrange
input = raw_input

t = int(input())

for _ in range(t):
    n = int(input())
    a = [ int(x) for x in input().split() ]

    ali, bob, pre, ans, i, j = 0, 0, 0, 0, 0, n - 1
    while i <= j:
        cur = 0
        if ans % 2 == 0:
            while i <= j and cur <= pre:
                cur += a[i]
                i += 1
            ali += cur
        else:
            while j >= i and cur <= pre:
                cur += a[j]
                j -= 1
            bob += cur
        pre = cur
        ans += 1
    
    print ans, ali, bob