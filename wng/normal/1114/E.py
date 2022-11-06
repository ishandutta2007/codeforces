n=int(input())
from sys  import stdout
import random

lim=10**9

def pgcd(a,b):
    while b!=0:
        r=a%b
        a,b=b,r
    return a

tt=1<<30
qs=60
maxval=0

while tt:
    if maxval+tt<=lim:
        print("> {}".format(maxval+tt))
        stdout.flush()
        rep=int(input())
        qs-=1
        if rep:
            maxval+=tt
    tt>>=1
maxval+=1

jaasked=set()

gotten=[]

for i in range(min(qs,n)):
    ta=random.randint(1,n)
    while ta in jaasked:
        ta=random.randint(1,n)
    jaasked.add(ta)
    print("? {}".format(ta))
    stdout.flush()
    gotten+=[maxval-int(input())]

ss=len(gotten)
pgcds=[]
for i in range(ss):
    for j in range(i):
        pgcds+=[pgcd(gotten[i],gotten[j])]

d=min([k for k in pgcds if k])

print("! {} {}".format(maxval-d*(n-1),d))