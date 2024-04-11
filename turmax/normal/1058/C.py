n=int(input())
s=str(input())
z=0
for k in s:
    if(k!="0"):
        z=1
if(z==0):
    print("YES")
while True:
    try:
        if(s[-1]=="0"):
            s=s[0:(len(s)-1):1]
        else:
            break
    except:
        break
S=0
for k in s:
    k=int(k)
    S+=k 
r=1
for i in range(2,S+1):
    if(S%i==0):
        m=0
        t=0
        d=0
        while(m<len(s)):
            while(t<(S/i)):
                try:
                    f=s[m]
                except:
                    d=1
                    break
                f=int(f)
                t+=f 
                if(t>(S/i)):
                    d=1
                m+=1
            t=0
        if(d==0):
            print("YES")
            r=0
            break
if(r==1 and z!=0):
    print("NO")