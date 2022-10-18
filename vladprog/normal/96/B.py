from math import*

s=set()
def f(t,k4,k7):
    global s
    if t and k4==k7:
        s|={int(t)}
    if len(t)==10:
        return
    f(t+'4',k4+1,k7)
    f(t+'7',k4,k7+1)
f('',0,0)
s=sorted(s)
n=int(input())
for x in s:
    if x>=n:
        print(x)
        exit()