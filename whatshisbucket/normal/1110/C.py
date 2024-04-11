import math
q=int(input())
for u in range(q):
    a=int(input())
    if math.log2(a+1)==int(math.log2(a+1)):
        q=1
        found=False
        while q<a**0.5:
            q+=1
            if a%q==0:
                found=True
                break
        if found:
            print(a//q)
        else:
            print(1)
    else:
        print(2**math.ceil(math.log2(a+1))-1)