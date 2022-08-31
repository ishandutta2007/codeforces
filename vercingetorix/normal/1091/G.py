import random
import sys
n = int(input())

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def ask(a):
    print('sqrt', a)
    sys.stdout.flush()
    return(int(input()))

a = set()

def add(x):
    if x != 1:
        a.add(x)

for i in range(50):
    x = random.randrange(0,n)
    while gcd(x,n) != 1:
        x = random.randrange(0,n)
    y = ask(x*x%n)
    if x==y or x+y==n:
        continue
    add(gcd(x+y,n))
    add(gcd(abs(x-y),n))

ans = []

while len(a)>0:
    d = 0
    for x in a:
        nd = gcd(d,x)
        if nd != 1:
            d = nd
    ans.append(str(d))
    rem = []
    app = []
    for x in a:
        if x % d == 0:
            rem.append(x)
            app.append(x//d)
    for x in rem:
        a.remove(x)
    for x in app:
        add(x)

print('!', len(ans), ' '.join(ans))
sys.stdout.flush()