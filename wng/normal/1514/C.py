from math import gcd
n=[int(i) for i in input().split()][0]

mods=[0]*n
res=[]
prod=1
for i in range(1,n):
    if (gcd(i,n)==1):
        res+=[str(i)]
        prod*=i
        prod%=n

if prod!=1:
    res=res[:-1]

print(len(res))
print(" ".join(res))