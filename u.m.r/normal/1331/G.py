f = []
for i in range(11):
    f.append(int(raw_input()))

from math import *

f.reverse()
for x in f:
    y = abs(x)
    z = sqrt(y) + x ** 3 * 5
    if (z < 400):
        print("f(%d) = %.2f" % (x, z))
    else:
        print("f(%d) = MAGNA NIMIS!" % (x))