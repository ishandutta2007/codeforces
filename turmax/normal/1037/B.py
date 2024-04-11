a,b=map(int,input().split())
t=[int(i) for i in input().split()]
t=sorted(t)
d1=t[int((a-1)/2):a:1]
d2=t[0:int((a+1)/2):1]
s1=0
for i in d1:
    if(i<b):
        s1+=(b-i)
s2=0
for i in d2:
    if(i>b):
        s2+=(i-b)
print(max(s1,s2))