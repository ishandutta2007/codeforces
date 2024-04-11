import math
t=input()
s=""
if len(t)%2==0:
    t=t[::-1]
for i in range(math.ceil(len(t)/2)):
    s+=t[i]+t[-i-1]
s=s[::-1]
if len(s)>len(t):
    print(s[1:])
else:
    print(s)