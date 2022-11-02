from math import *
s=raw_input()
u,t,l,k=1,set(),len(s),0
for i in range(l):
    if (s[i]>='A')and(s[i]<='J')and(s[i] not in t):
        if (i==0):u*=9
        else:u*=(10-len(t))
        t.add(s[i])
    else:k+=s[i]=='?'
if (s[0]=='?'):
    u*=9
    k-=1
print str(u)+'0'*k