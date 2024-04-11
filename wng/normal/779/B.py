
a,b=raw_input().split(" ")
k=int(b)
i=-1
r=0
l=len(a)
while k>0 :
    if a[i]=="0":
        k-=1
    else:
        r+=1
    if -i==l:
        r=l-1
        k=0
    i-=1
print r