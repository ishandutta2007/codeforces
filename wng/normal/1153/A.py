
n,t=[int(k) for k in input().split(" ")]
mw=100000000000000
nbest=-1

for i in range(n):
    s,d=[int(k) for k in input().split(" ")]
    if t<s:
        w=s-t
    else:
        w=(d-(t-s))%d
    #print(s,d,w,mw,nbest)
    if w<mw:
        mw=w
        nbest=i+1
print(nbest)