from itertools import *
s=raw_input()
u=lambda x,e:all(any(a==b for a in e) for b in str(x))
r=next(ifilter(lambda x:u(x,iter(s)),range(0,1000,8)),1)
print("YES\n%d"%r if r!=1 else "NO")