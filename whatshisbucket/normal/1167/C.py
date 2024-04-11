import os
import sys
from atexit import register
from io import BytesIO

sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = lambda: sys.stdin.readline().rstrip('\r\n')
n,m=map(int,input().split())
graph=[[] for i in xrange(n)]
for i in xrange(m):
    a=list(map(int,input().split()))
    if a[0]>1:
        for j in xrange(len(a)-2):
            graph[a[j+2]-1].append(a[1]-1)
            graph[a[1]-1].append(a[j+2]-1)
components=[0]*n
comp=0
for i in xrange(n):
    if components[i]==0:
        comp+=1
        components[i]=comp
        layer=[i]
        while layer!=[]:
            newlayer=[]
            for guy in layer:
                for guy1 in graph[guy]:
                    if components[guy1]==0:
                        newlayer.append(guy1)
                        components[guy1]=comp
            layer=newlayer
count=[0]*(comp+1)
for guy in components:
    count[guy]+=1
out=""
out=[str(count[guy]) for guy in components]
print(" ".join(out))