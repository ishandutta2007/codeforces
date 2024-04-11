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
def let(x):
    if x==0:
        return "A"
    if x==1:
        return "C"
    if x==2:
        return "G"
    return "T"
n,m=map(int,input().split())
rows=[[[0,0,0,0],[0,0,0,0]] for i in range(n)]
cols=[[[0,0,0,0],[0,0,0,0]] for i in range(m)]
for i in range(n):
    s=input()
    if i==0:
        save=s[:4]
    for j in range(m):
        if s[j]=="A":
            rows[i][j%2][0]+=1
            cols[j][i%2][0]+=1
        elif s[j]=="C":
            rows[i][j%2][1]+=1
            cols[j][i%2][1]+=1
        elif s[j]=="G":
            rows[i][j%2][2]+=1
            cols[j][i%2][2]+=1
        else:
            rows[i][j%2][3]+=1
            cols[j][i%2][3]+=1
best=(0,None)
for i in range(4):
    for j in range(4):
        for k in range(4):
            for l in range(4):
                if i<j and k<l and i!=k and j!=l and j!=k and i!=l:
                    sumi=0
                    for w in range(n):
                        if w%2==0:
                            sumi+=max(rows[w][0][i]+rows[w][1][j],rows[w][0][j]+rows[w][1][i])
                        else:
                            sumi+=max(rows[w][0][k]+rows[w][1][l],rows[w][0][l]+rows[w][1][k])
                    if sumi>best[0]:
                        best=(sumi,(i,j,k,l))
best1=(0,None)
for i in range(4):
    for j in range(4):
        for k in range(4):
            for l in range(4):
                if i<j and k<l and i!=k and j!=l and j!=k and i!=l:
                    sumi=0
                    for w in range(m):
                        if w%2==0:
                            sumi+=max(cols[w][0][i]+cols[w][1][j],cols[w][0][j]+cols[w][1][i])
                        else:
                            sumi+=max(cols[w][0][k]+cols[w][1][l],cols[w][0][l]+cols[w][1][k])
                    if sumi>best1[0]:
                        best1=(sumi,(i,j,k,l))
if best[0]>best1[0]:
    i,j,k,l=best[1][0],best[1][1],best[1][2],best[1][3]
    for w in range(n):
        if w%2==0:
            if rows[w][0][i]+rows[w][1][j]>rows[w][0][j]+rows[w][1][i]:
                print(((let(i)+let(j))*(m//2+1))[:m])
            else:
                print(((let(j)+let(i))*(m//2+1))[:m])
        else:
            if rows[w][0][k]+rows[w][1][l]>rows[w][0][l]+rows[w][1][k]:
                print(((let(k)+let(l))*(m//2+1))[:m])
            else:
                print(((let(l)+let(k))*(m//2+1))[:m])
else:
    i,j,k,l=best1[1][0],best1[1][1],best1[1][2],best1[1][3]
    lets=[[0]*m for p in range(n)]
    for w in range(m):
        if w%2==0:
            if cols[w][0][i]+cols[w][1][j]>cols[w][0][j]+cols[w][1][i]:
                for x in range(n):
                    lets[x][w]=let(i) if x%2==0 else let(j)
            else:
                for x in range(n):
                    lets[x][w]=let(j) if x%2==0 else let(i)
        else:
            if cols[w][0][k]+cols[w][1][l]>cols[w][0][l]+cols[w][1][k]:
                for x in range(n):
                    lets[x][w]=let(k) if x%2==0 else let(l)
            else:
                for x in range(n):
                    lets[x][w]=let(l) if x%2==0 else let(k)
    for w in range(n):
        print("".join(lets[w]))