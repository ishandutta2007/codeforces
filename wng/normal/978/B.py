#978b

n=int(raw_input())
s=raw_input()

x=0
res=0
for i in s:
    if i=="x":
        x+=1
    else:
        x=0
    if x>2:
        res+=1
print res