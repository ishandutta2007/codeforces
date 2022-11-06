m,b=[int(k) for k in raw_input().split(" ")]

x=b*m
y=0
res=0

while x>0:
   res=max(res,(x+1)*(y+1)*((x+y))/2)
   x-=m
   y+=1
   
print(res)