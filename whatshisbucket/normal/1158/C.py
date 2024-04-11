import os
import sys
from atexit import register
from io import BytesIO

sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = lambda: sys.stdin.readline().rstrip('\r\n')
t=int(input())

for u in xrange(t):
    n=int(input())
    a=list(map(int,input().split()))
    long=[]
    lens=0
    fucked=False
    for i in xrange(n):
        if a[i]==-1:
            if lens==0:
                a[i]=i+2
            else:
                a[i]=long[-1]
        else:
            if lens==0 or a[i]<long[-1]:
                long.append(a[i])
                lens+=1
            elif lens>0 and a[i]>long[-1]:
                fucked=True
        if lens>0:
            if i>=long[-1]-2:
                long.pop()
                lens-=1
    if fucked:
        print(-1)
    else:
        back={}
        for i in xrange(n+1):
            back[i+1]=[]
        for i in xrange(n):
            back[a[i]].append(i+1)
        perm=[0]*n
        q=[n+1]
        big=n
        while q!=[]:
            newq=[]
            for guy in q:
                for boi in back[guy]:
                    perm[boi-1]=big
                    big-=1
                newq+=back[guy]
            q=newq
        perm=[str(guy) for guy in perm]
        print(" ".join(perm))