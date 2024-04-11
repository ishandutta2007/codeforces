n=int(raw_input())
s=[int(k) for k in raw_input().split(" ")]


isok=True

for k in s[1:]:
   if k%s[0]!=0:
        isok=False
        break
    
if not isok:
    print "-1"
else:
    res=(" {} ".format(s[0])).join([str(k) for k in s])
    print len(s)*2-1
    print res