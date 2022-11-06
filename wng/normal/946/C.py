#[int(k) for k in raw_input().split(" ")]

letters="abcdefghijklmnopqrstuvwxyz"
ids=dict(zip(letters,range(26)))

s=raw_input()


res=[]
k=0
trp=[]
for i in range(len(s)):
    if s[i]<=letters[k]:
        res+=[letters[k]]
        k+=1
    else:
        res+=[s[i]]
    if k>25:
        break
if k>25:
    res="".join(res+[k for k in s[i+1:]])
else:
    res=-1
print res