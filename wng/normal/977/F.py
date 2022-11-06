
n=[int(k) for k in raw_input().split(" ")][0]
a=[int(k) for k in raw_input().split(" ")]
r={}
for i in a:
    if i in r:
        r[i+1]=r[i]+1
    else:
        r[i+1]=1

mv=max(r.values())

mr=[k-1 for k in r if r[k]==mv][0]

tg=mr-mv+1
res=[]
for i in range(n):
    if a[i]==tg:
        tg+=1
        res+=[str(i+1)]
     #  print i,a[i]

print len(res)        
print " ".join(res)