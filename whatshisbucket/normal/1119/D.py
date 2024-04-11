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
def main():
    n=int(input())
    s=list(map(int,input().split()))
    if n==1:
        q=int(input())
        out=[0]*q
        for u in range(q):
            a,b=map(int,input().split())
            out[u]=str(b-a+1)
        print(" ".join(out))
        exit()
    s.sort()
    diffs=[s[i+1]-s[i] for i in range(n-1)]
    diffs.sort()
    parts=[0]*(n-1)
    parts[0]=diffs[0]*n
    for i in range(n-2):
        parts[i+1]=parts[i]+(diffs[i+1]-diffs[i])*(n-i-1)
    q=int(input())
    out=[0]*q
    for u in range(q):
        a,b=map(int,input().split())
        size=b-a+1
        if size<=diffs[0]:
            out[u]=n*size
        elif size>=diffs[-1]:
            out[u]=parts[-1]+size-diffs[-1]
        else:
            big=n-2
            sml=0
            curr=(n-2)//2
            while big-sml>1:
                if size>diffs[curr]:
                    sml=curr
                    curr=(big+sml)//2
                elif size<diffs[curr]:
                    big=curr
                    curr=(big+sml)//2
                else:
                    big=sml=curr
            if big==sml:
                out[u]=parts[big]
            else:
                rat=(parts[big]-parts[sml])//(diffs[big]-diffs[sml])
                out[u]=parts[sml]+rat*(size-diffs[sml])
    out=[str(guy) for guy in out]
    print(" ".join(out))
main()