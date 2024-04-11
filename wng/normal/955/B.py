s=raw_input()
d={}
for i in s:
    if i not in d:
        d[i]=0
    d[i]+=1

ss=sorted(d.values(),reverse=True)

res="No"
if len(ss)==4:
    res="Yes"
if len(ss)==2 and ss[1]>1:
    res="Yes"
if len(ss)==3 and ss[0]>1:
    res="Yes"

print res