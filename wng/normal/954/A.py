n=int(raw_input())
s=raw_input()
previous="#"
res=0
for i in s:
    res+=1
    if "".join(sorted(previous+i))=="RU":
        previous="#"
        res-=1
    else:
        previous=i
print res