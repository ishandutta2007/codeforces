

a,b,c=[int(k) for k in raw_input().split(" ")]

d=set([])

a=a%b
res=0

while True:
    d.add(a)
    res+=1
    a*=10
    dd=a/b
    a=a%b
    if dd==c:
        break
    if a in d:
        res=-1
        break

print res