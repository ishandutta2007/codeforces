import math
n=int(raw_input())
x=[0]*n
y=[0]*n
for i in range(n):
    x[i],y[i]=[int(k) for k in raw_input().split(" ")]

#for each point i , we look how far i-1 is from the line (i-2,i)
mind=10**11
for i in range(n):
    a,b,c=(x[i-2],y[i-2]),(x[i-1],y[i-1]),(x[i],y[i])
    area=abs(a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]))/2.0
    ac=math.sqrt((a[0]-c[0])**2+(a[1]-c[1])**2)
    mind=min(mind,area/ac) #demi hauteur
 #   print a,b,c,area,ac,area/ac
print mind