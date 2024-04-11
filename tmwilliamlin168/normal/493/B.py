n=int(input())
s0=s1=0
a0,a1=[],[]
l0=l1=-1
for i in range(n):
    a=int(input())
    if a>0:
        s0+=a
        a0+=[a]
        l0=i
    else:
        s1+=-a
        a1+=[-a]
        l1=i
print('first' if (s0, a0, l0)>(s1, a1, l1) else 'second')