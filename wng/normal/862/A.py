#[int(k) for k in raw_input().split(" ")]


n,x=[int(k) for k in raw_input().split(" ")]
s=[int(k) for k in raw_input().split(" ")]
res=0;
for i in range(x):
    if i not in s:
        res+=1
if x in s:
    res+=1
    
print res