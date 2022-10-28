def f(mag):
    if len(mag)==1:
        return([])
    elif mag[-1]=="b":
        return(f(mag[:-1]))
    else:
        boi=len(mag)
        old=f(mag[:-1])
        if boi-1 in old:
            old.pop()
            old.append(boi)
            return(old)
        else:
            old.append(boi-1)
            old.append(boi)
            return(old)
string=input()
k=f(string)
out=""
for i in range(len(string)):
    if i+1 in k:
        out+="1 "
    else:
        out+="0 "
print(out[:-1])