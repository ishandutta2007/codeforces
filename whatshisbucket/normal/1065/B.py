import math
x=input()
x=x.split()
n=int(x[0])
m=int(x[1])
if m>=n/2:
    min=0
else:
    min=n-2*m
max=n-math.ceil((2*m+(2*m)**(1/2))**(1/2))
print(str(min)+" "+str(max))