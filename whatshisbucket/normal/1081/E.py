import math
n=int(input())
x=list(map(int,input().split()))
currsum=0
others=[]
done=False
for i in range(n//2):
    a=x[i]
    sml=None
    big=None
    if a%4==2:
        print("No")
        done=True
        break
    elif a%2==1:
        for i in range(1,math.ceil(-currsum+(currsum**2+a)**0.5),2):
            if a%i==0:
                sml=((a-i**2)//(2*i))**2
                big=sml+a
    else:
        for i in range(2,math.ceil(-currsum+(currsum**2+a)**0.5),2):
            if a%(2*i)==0:
                sml=((a-i**2)//(2*i))**2
                big=sml+a
    if sml==None:
        print("No")
        done=True
        break
    others.append(sml-int(currsum)**2)
    currsum=big**0.5
if not done:
    out=""
    for i in range(n//2):
        out+=str(others[i])+" "+str(x[i])+" "
    print("Yes")
    print(out[:-1])