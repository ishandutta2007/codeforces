n=int(input())
a=[]
b=[]
if n==3:
    print("1 2 3")
else: 
    for i in range(n):
        x,y=map(int,input().split())
        a.append(x)
        b.append(y)
    real=[1]
    for i in range(n-1):
        c,d=a[real[-1]-1],b[real[-1]-1]
        if d==a[c-1] or d==b[c-1]:
            real.append(c)
        else:
            real.append(d)
    out=""
    for guy in real:
        out+=str(guy)+" "
    print(out)