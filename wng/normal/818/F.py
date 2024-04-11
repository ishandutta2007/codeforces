n=int(raw_input())
import math

def revt(x):
    return int(math.ceil((math.sqrt(8*x+1)-1)/2))

for i in range(n):
    k=int(raw_input())
    rk=k-revt(k)
    if k==1:
        print 0
    else:
        print max(rk+min(rk,(k-rk)*(k-rk-1)/2),(rk+1)+min(rk+1,(k-rk-1)*(k-rk-2)/2))