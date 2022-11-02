R=lambda:map(int,raw_input().split())
res,t,w=1e9,0,0
def check(a,b):
    global res,t,w
    if (abs(x*b-y*a)*y*w<res*y*b):res,t,w=abs(x*b-y*a),a,b
x,y,n=R()
for b in xrange(1,n+1):
    a=x*b/y
    check(a,b)
    a=(x*b/y)+1
    check(a,b)
print "/".join(map(str,[t,w]))