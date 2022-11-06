#[int(k) for k in raw_input().split(" ")]

a=raw_input()

start=False
res=0
for k in a:
    if k=="1":
        start=True
    if start and k=="0":
        res+=1

if res>=6:
    print "yes"
else:
    print "no"