n,d=[int(k) for k in raw_input().split(" ")]
a=[-10**10]+[int(k) for k in raw_input().split(" ")]+[10**10]

res=-2
dmin=2*d
for i in range(n+1):
    md=a[i+1]-a[i]    
    if md==dmin:
        res+=1
    elif md>dmin:
        res+=2
   # print md
    
print res