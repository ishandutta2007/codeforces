n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]
d={}

for k in a:
    if k not in d:
        d[k]=0
    d[k]+=1

willConanwin=False
for k in d.values():
    if k%2==1:
        willConanwin=True
        break

if willConanwin:
    print "Conan"
else:
    print "Agasa"