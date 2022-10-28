import os
import sys
from atexit import register
from io import BytesIO

sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = lambda: sys.stdin.readline().rstrip('\r\n')
def g(tup):
    return(tup[0]-tup[1])
n,m=map(int,input().split())
score=[None]*n
for i in xrange(n):
    a,b=map(int,input().split())
    score[i]=(a,b,i+1)
scores=sorted(score,key=g)
run2=sum(x[1] for x in scores)
run1=0
scored=[0]*n
for i in xrange(n):
    a=scores[i]
    run2-=a[1]
    points=run1+run2
    run1+=a[0]
    points+=a[0]*(n-i-1)
    points+=a[1]*i
    scored[a[2]-1]=points
for i in xrange(m):
    a,b=map(int,input().split())
    points=min(score[a-1][1]+score[b-1][0],score[a-1][0]+score[b-1][1])
    scored[a-1]-=points
    scored[b-1]-=points
scored=[str(guy) for guy in scored]
print(" ".join(scored))