f,x,t=map(int,raw_input().split())
l=[0]*20
for i in range(f):
 s=raw_input().split()[0]
 for j in range(x):
  if(s[j]=='Y'):
   l[j]+=1
y=0
for j in range(x):
 if(l[j]>=t):
  y+=1
print(y)#a kitten