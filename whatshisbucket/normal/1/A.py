import math
x=input()
x=x.split()
a=math.ceil(int(x[0])/int(x[2]))
b=math.ceil(int(x[1])/int(x[2]))
print(a*b)