a,b=map(int,input().split())
m=[int(i) for i in range(1,b+1)]
m=set(m)
for i in range(0,a):
    c,d=map(int,input().split())
    b=set([int(u) for u in range(c,d+1)])
    m-=b
print(len(m))
for k in range(0,len(m)):
    print(m.pop())