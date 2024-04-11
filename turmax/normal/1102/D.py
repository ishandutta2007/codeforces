def opt(n1,n2,n3,n):
    v=(n//3)
    return(max(abs(n1-v),abs(n2-v),abs(n3-v)))
n=int(input())
d=str(input())
s=[d[i] for i in range(n)]
n1=s.count('0')
n2=s.count('1')
n3=s.count('2')
for i in range(0,len(s)):
    a=s[i]
    if(a=='1'):
        if(opt(n1+1,n2-1,n3,n)==(opt(n1,n2,n3,n)-1)):
            s[i]='0'
            n1+=1
            n2-=1
    elif(a=='2'):
        if(opt(n1+1,n2,n3-1,n)==(opt(n1,n2,n3,n)-1)):
            s[i]='0'
            n1+=1
            n3-=1
        elif(opt(n1,n2+1,n3-1,n)==(opt(n1,n2,n3,n)-1)):
            s[i]='1'
            n2+=1
            n3-=1
u=n//3
v1=(n1-u)
v2=(n2-u)
v3=(n3-u)
if(v2>=0):
    for i in range(len(s)-1,(-1),(-1)):
        if(s[i]=='1'):
            if(v2>0):
                s[i]='2'
                v2-=1
                v3+=1
        elif(s[i]=='0'):
            if(v1>0):
                s[i]='2'
                v1-=1
                v3+=1
else:
    for i in range(len(s)-1,(-1),(-1)):
        if(s[i]=='0'):
            if(v3<0):
                s[i]='2'
                v1-=1
                v3+=1
            elif(v2<0):
                s[i]='1'
                v1-=1
                v2+=1
for i in s:
    print(i,end="")