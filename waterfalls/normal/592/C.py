from fractions import gcd

t,w,b = map(int,input().split())
per = w*b//gcd(w,b)
can = (t//per+1)*min(w,b)-1
if t%per<min(w,b):
    can-=min(w,b)
    can+=t%per+1
g = gcd(can,t)
can//=g
t//=g
print(str(can)+"/"+str(t))