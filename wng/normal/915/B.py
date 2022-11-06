n, pos, l, r=[int(k) for k in raw_input().split(" ")]

if l!=1 and r!=n:
    res=(r-l)+  min(abs(pos-l),abs(pos-r))+2
elif l==1 and r!=n:
    res=abs(pos-r)+1
elif r==n and l!=1:
    res=abs(pos-l)+1
else:
    res=0
print res