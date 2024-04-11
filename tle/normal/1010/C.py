def gcd(a,b):
    while b:
        a,b=b,a%b
    return a
n,k=map(int,raw_input().split(' '))
g=0
a=map(int,raw_input().split(' '))
for x in a:
    g=gcd(g,x)
s=0
v=[0]*k
while not v[s]:
    v[s]=1
    s=(s+g)%k
t=[]
for i in range(0,k):
    if v[i]:
        t.append(i)
print len(t)
print ' '.join(map(str,t))