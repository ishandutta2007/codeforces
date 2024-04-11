T=int(input())

for Tid in range(T):
    n=int(input())
    a=[]
    for i in range(n):
        a.append(input())
    a0,a1,a2=[],[],[]
    def add(x,y,c):
        if a[x][y]==c:
            a0.append([x+1,y+1])
        else:
            a1.append([x+1,y+1])
    add(0,1,'0')
    add(1,0,'0')
    add(n-1,n-2,'1')
    add(n-2,n-1,'1')
    if len(a0)<len(a1):
        a2=a0
    else:
        a2=a1
    print(len(a2))
    for i in range(len(a2)):
        print(a2[i][0],a2[i][1])