n=int(raw_input())
a=raw_input()
nb0=0
for i in range(n):
    if a[i]=="0":
        nb0+=1

res=("1" if a!="0" else "")+"0"*nb0
print res