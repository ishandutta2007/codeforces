a=int(input())
strings=[]
win=False
for i in range(a):
    b=input()
    if b[0:2]=="OO" and win==False:
        strings.append("++"+b[2:])
        win=True
    elif b[3:5]=="OO" and win==False:
        strings.append(b[:3]+"++")
        win=True
    else:
        strings.append(b)
if win==True:
    print("YES")
    for i in range(a):
        print(strings[i])
else:
    print("NO")