n,a,b=[int(k) for k in raw_input().split(" ")]
s=[int(k) for k in raw_input().split(" ")]
fh=s[0]
sm=sum(s)
st=sorted(s[1:],reverse=True)
res=0
while a*fh<b*sm:
    sm-=st[res]
    res+=1

print res