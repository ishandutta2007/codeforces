f=lambda:[*map(int,input().split())]
for _ in[0]*f()[0]:
 n,s=f();a,x=f(),[-1];l,b,e,t,w=[0]*5
 while 1:
  if w>=-s:
   if e-b>l:l=e-b;x=[b+1,e]
   if e>=n:print(*x);break
   t+=a[e];w=min(w,t);e+=1
  else:w=t=t-a[b];b+=1