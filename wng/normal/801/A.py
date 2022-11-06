w=raw_input("")
bonus=0
res=0
for i in range(len(w)-1):
    if w[i]=="V" or  w[i+1]=="K":
        if w[i]=="V" and  w[i+1]=="K":
            res+=1
        else:
            if (w[i]=="K" and (i==0 or w[i-1]!="V")) or (w[i+1]=="V" and (i==len(w)-2 or w[i+2]!="K")):
                bonus=1
print (res+bonus)