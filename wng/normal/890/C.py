n=int(raw_input())
a=[int(k) for k in raw_input().split(" ")]

dv=set()
nbv=1
for k in range(n):
    ak=a[k]
    if ak in dv:
        nbv+=1
    else:
        dv.add(ak)
print nbv