import math
a,b,c=map(int,input().split())
d,e,f=map(int,input().split())
g=math.gcd(c,f)
int1=[a%g,b%g]
in1=b//g-a//g
int2=[d%g,e%g]
in2=e//g-d//g
int1[1]+=g*in1
int2[1]+=g*in2
maybegood=max(min(int1[1],int2[1])-max(int1[0],int2[0])+1,0)
int2[0]+=g
int2[1]+=g
maybegood1=max(min(int1[1],int2[1])-max(int1[0],int2[0])+1,0)
int2[0]-=2*g
int2[1]-=2*g
maybegood2=max(min(int1[1],int2[1])-max(int1[0],int2[0])+1,0)
print(max(maybegood,maybegood1,maybegood2))