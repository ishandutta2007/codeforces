import os
import sys
from atexit import register
from io import BytesIO

sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))

input = lambda: sys.stdin.readline().rstrip('\r\n')
q=int(input())
home=[]
last=0
parents={}
for i in xrange(q):
    a=list(map(int,input().split()))
    for i in xrange(len(a)-1):
        a[i+1]=a[i+1]^last
    start,end=min(a[1],a[2])-1,max(a[1],a[2])
    x,y=start in parents,end in parents
    if x:
        if y:
            xor=parents[start][1]
            daddy=parents[start][0]
            child=start
            long=[]
            while True:
                if child==daddy:
                    break
                long.append((child,parents[child][1]))
                xor=xor^parents[daddy][1]
                child=daddy
                daddy=parents[daddy][0]
            xor3=0
            for guy in long[::-1]:
                xor3^=guy[1]
                parents[guy[0]]=(daddy,xor3)
            xor1=parents[end][1]
            daddy1=parents[end][0]
            child1=end
            long=[]
            while True:
                if child1==daddy1:
                    break
                long.append((child1,parents[child1][1]))
                xor1=xor1^parents[daddy1][1]
                child1=daddy1
                daddy1=parents[daddy1][0]
            xor2=0
            for guy in long[::-1]:
                xor2^=guy[1]
                parents[guy[0]]=(daddy1,xor2)
            if a[0]==2:
                if daddy==daddy1:
                    last=xor^xor1
                    print(last)
                else:
                    print(-1)
                    last=1
            else:
                if daddy!=daddy1:
                    parents[daddy]=(parents[daddy1][0],xor1^xor^a[3])
        else:
            if a[0]==2:
                print(-1)
                last=1
            else:
                parents[end]=(parents[start][0],a[3]^parents[start][1])
    else:
        if y:
            if a[0]==2:
                print(-1)
                last=1
            else:
                parents[start]=(parents[end][0],a[3]^parents[end][1])
        else:
            if a[0]==2:
                print(-1)
                last=1
            else:
                home.append(start)
                parents[end]=(start,a[3])
                parents[start]=(start,0)