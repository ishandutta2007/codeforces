from fractions import gcd
n = int(raw_input())
nn = n/2
dd = n - nn
while gcd(nn, dd) > 1:
    nn -= 1
    dd += 1
print "{} {}".format(nn, dd)