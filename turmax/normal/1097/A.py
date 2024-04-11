d1=["2","3","4","5","6","7","8","9","T","J","Q","K","A"]
d2=["D","C","S","H"]
x=str(input())
f=x[0]
g=x[1]
s=str(input())
o=s.split()
f0=[l[0] for l in o]
g0=[l[1] for l in o]
if((f in f0) or (g in g0)):
    print("YES")
else:
    print("NO")