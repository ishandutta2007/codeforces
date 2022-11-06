a,b,c=[int(k) for k in raw_input().split(" ")]
n=int(raw_input())
x=[int(k) for k in raw_input().split(" ")]
res=0
for i in x:
    if i>b and i<c:
        res+=1
        
print res