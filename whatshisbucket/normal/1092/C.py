n=int(input())
strs=[]
for i in range(2*n-2):
    strs.append(input())
strd=sorted(strs,key=len,reverse=True)
poss1=strd[0]+strd[1][-1]
poss2=strd[1]+strd[0][-1]
real=poss1
for guy in strd:
    a=len(guy)
    if guy!=poss1[:a] and guy!=poss1[-a:]:
        real=poss2
        break
    if guy!=poss2[:a] and guy!=poss2[-a:]:
        break
out=""
for guy in strs:
    a=len(guy)
    x,y=guy==real[:a],guy==real[-a:]
    if x:
        if y:
            out+="B"
        else:
            out+="P"
    else:
        out+="S"
stuff=[0]*(n-1)
for i in range(2*n-2):
    if out[i]=="B":
        stuff[len(strs[i])-1]+=10
    elif out[i]=="P":
        stuff[len(strs[i])-1]+=1
    else:
        stuff[len(strs[i])-1]-=1
for i in range(2*n-2):
    if out[i]=="B":
        if stuff[len(strs[i])-1]==9:
            out=out[:i]+"P"+out[i+1:]
        else:
            out=out[:i]+"S"+out[i+1:]
            stuff[len(strs[i])-1]-=11
print(out)