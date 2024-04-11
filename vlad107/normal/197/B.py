n,m=map(int,raw_input().split())
a=map(int,raw_input().split())
b=map(int,raw_input().split())
def gcd(x,y):return x+y if(x*y==0)else gcd(y%x,x)
    
x,y=a[0],b[0]
if (n>m):
    print 'Infinity'if(x*y>0)else '-Infinity'
else:
    if (n<m):x=0
    sx=str(x/gcd(x,y))
    sy=str(y/gcd(x,y))
    if (sy[0]=='-'):
        sx='-'+sx
        sy=sy[1:]
    print sx+'/'+sy