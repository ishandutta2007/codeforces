l,r=[int(k) for k in raw_input().split(" ")]

#generation of the list

d=set()

i2=1

while i2<=r:
    mx=r/i2
    i3=1
    while i3<=mx:
        d.add(i3*i2)
        i3*=3
    i2*=2
res=0
for k in d:
    if k>=l:
        res+=1
        
print res