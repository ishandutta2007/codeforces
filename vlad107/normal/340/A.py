G=lambda x,y:x+y if x*y==0 else G(y,x%y)
x,y,a,b=map(int,raw_input().split())
T=x*y/G(x,y)
print b/T-(a-1)/T