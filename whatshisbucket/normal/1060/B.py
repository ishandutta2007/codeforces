x=input()
x=x[len(x)-1:0:-1]+x[0]
max=0
goodboi=0
for i in range(len(x)):
    if goodboi==1 and i<len(x)-1:
        max+=(int(x[i])+9)
    elif i==len(x)-1:
        max+=(int(x[i])-goodboi)
    else:
        if int(x[i])==9:
            max+=9
        else:
            max+=(int(x[i])+10)
            goodboi=1
print(max)