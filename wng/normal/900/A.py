#[int(k) for k in raw_input().split(" ")]

n=int(raw_input())
np=0
nn=0
for i in range(n):
    a=[int(k) for k in raw_input().split(" ")]
    if a[0]<0:
        nn+=1
    else:
        np+=1

if min(np,nn)<=1:
    print "Yes"
else:
    print "No"