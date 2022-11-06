n,h=[int(k) for k in raw_input().split(" ")]
from math import sqrt
sn=sqrt(n)
res=[h*sqrt(k)/sn for k in range(1,n)]

print " ".join(["{:.8f}".format(k) for k in res])