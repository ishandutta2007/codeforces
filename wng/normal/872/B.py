n,k=[int(i) for i in raw_input().split(" ")]
a=[int(i) for i in raw_input().split(" ")]

if k==1:
    print min(a)
if k>2:
    print max(a)
if k==2:
    print max(a[0],a[-1])