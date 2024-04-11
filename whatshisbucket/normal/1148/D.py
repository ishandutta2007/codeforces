import os
import sys
from io import IOBase
from bisect import bisect_right, bisect_left

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from cStringIO import StringIO
    from future_builtins import ascii, filter, hex, map, oct, zip
else:
    from io import BytesIO as StringIO

sys.stdout, stream = IOBase(), StringIO()
sys.stdout.flush = lambda: os.write(1, stream.getvalue()) and not stream.truncate(0) and stream.seek(0)
sys.stdout.write = stream.write if sys.version_info[0] < 3 else lambda s: stream.write(s.encode())

input, flush = sys.stdin.readline, sys.stdout.flush
input = StringIO(os.read(0, os.fstat(0).st_size)).readline
def sec(tup):
    return tup[1]
n=int(input())
inc=[]
dec=[]
for i in range(1,n+1):
    a,b=map(int,input().split())
    if a<b:
        inc.append((a,b,i))
    else:
        dec.append((a,b,i))
inc.sort(reverse=True)
dec.sort(key=sec)
if len(inc)>len(dec):
    print(len(inc))
    print(" ".join([str(guy[2]) for guy in inc]))
else:
    print(len(dec))
    print(" ".join([str(guy[2]) for guy in dec]))