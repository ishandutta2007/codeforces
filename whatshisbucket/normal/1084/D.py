import os
import sys
from atexit import register
from io import BytesIO

sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = lambda: sys.stdin.readline().rstrip('\r\n')
n=int(input())
w=list(map(int,input().split()))
edges=[[] for i in xrange(n)]
for i in xrange(n-1):
    a,b,c=map(int,input().split())
    edges[a-1].append((b-1,c))
    edges[b-1].append((a-1,c))
parents=[None]*n
layers=[{0}]
while True:
    newlayer=[]
    for guy in layers[-1]:
        for neigh in edges[guy]:
            if neigh[0]!=parents[guy]:
                newlayer.append(neigh[0])
                parents[neigh[0]]=guy
    if newlayer!=[]:
        layers.append(set(newlayer))
    else:
        break
b1=[None]*n
b2=[None]*n
for layer in layers[::-1]:
    for guy in layer:
        goods=[]
        for guy1 in edges[guy]:
            if guy1[0]!=parents[guy]:
                goods.append(b1[guy1[0]]-guy1[1])
        big1=0
        big2=0
        for boi in goods:
            if boi>big1:
                big1,big2=boi,big1
            elif boi>big2:
                big2=boi
        b1[guy]=w[guy]+big1
        b2[guy]=w[guy]+big1+big2
print(max(b2))