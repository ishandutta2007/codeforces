from fractions import gcd
import sys

a, b = (int(x) for x in raw_input().split())

if gcd(a, b) > 1:
    print "Impossible"
    sys.exit(0)

# (a, b) goes to (a-b, b) or (a, b-a)
ret = []
while a > 1 or b > 1:
    assert a != b
    if a > b:
        if a%b == 0:
            ret.append((a/b-1, "A"))
        else:
            ret.append((a/b, "A"))
        a %= b
    else:
        if b%a == 0:
            ret.append((b/a-1, "B"))
        else:
            ret.append((b/a, "B"))
        b %= a
ans = ""
for x in ret:
    ans += "{}{}".format(x[0], x[1])
print ans