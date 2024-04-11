import math
k=int(input())
init=[0]*1997+[-1,1]
init[-1]+=math.ceil((k+999)/1998)
curr=(init[-1]-1)*1999-init[-1]
init[-2]-=curr-k
init[-1]+=curr-k
print(1999)
init=[str(guy) for guy in init]
print(" ".join(init))