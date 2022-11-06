n=[int(k) for k in raw_input().split(" ")][0]
m=[int(k) for k in raw_input().split(" ")][0]
a=[float(k) for k in raw_input().split(" ")]
b=[float(k) for k in raw_input().split(" ")]

eps=10**-7

def cando(f):
    for i in range(n):
        w=f+m
        wto=w/a[i]
        f-=wto
        if f<-eps:
            return False
        w=f+m
        wto=w/b[(i+1)%n]
        f-=wto
        if f<-eps:
            return False
    return True



f=0
ta=10**9

if not cando(ta):
    print -1
else:
    while ta>=max(eps, eps*f):
        if not cando(f+ta):
            f+=ta
        ta/=2.

    print "{:.7f}".format(f + ta*2)