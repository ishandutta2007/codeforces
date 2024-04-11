w,h=map(int,input().split())
a,b=map(int,input().split())
c,d=map(int,input().split())
if b<d:
    a,b,c,d=c,d,a,b
w1=w+((h+b)*(h-b+1))//2
w1-=a
if w1<0:
    w1=0
w2=w1+((b-1+d)*(b-d))//2
w2-=c
if w2<0:
    w2=0
w3=w2+((d-1)*d)//2
print(w3)