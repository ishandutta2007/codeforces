n,w56=map(int,input().split())
if(n==1):
    x=[int(input())]
else:
    x=[int(i) for i in input().split()]
k,w90=map(int,input().split())
if(k==1):
    y=[int(input())]
else:
    y=[int(i) for i in input().split()]
t=0
import collections
for i in range(1,35):
    m=collections.Counter()
    for j in range(n):
        m[((x[j]-(2**(i-1)))%(2**i))]+=1
    for j in range(k):
        m[(y[j])%(2**i)]+=1
    t=max(t,max([m[o] for o in m.keys()]))
if(t>=2):
    print(t)
else:
    p=0
    for i in range(len(x)):
        for j in range(len(y)):
            if(x[i]==y[j]):
                print(2)
                p=1
                break
        if(p==1):
            break
    if(p==0):
        print(1)