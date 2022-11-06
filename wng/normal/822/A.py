a,b=[int(k) for k in raw_input().split(" ")]

res=1

for i in range(1,min(a,b)+1):
    res*=i

print res