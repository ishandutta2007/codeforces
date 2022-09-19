def swap(s,a,m):
    s=s[0:a:1]+m+s[(a+1):len(s):1]
    return(s)
i=int(input())
s=[int(k) for k in input().split()]
import collections
d=collections.Counter()
p=0
z=0
x=0
e=[]
r=-1
for t in s:
    u=[]
    for m in range(0,len(s)):
        if(s[m]==t):
            u.append(m)
    if(len(u)==1):
        e.append(t)
        p+=1
        z=1
    elif(len(u)>=3):
        x=1
        r=t
    d[t]=tuple(u)
y="0"*i 
if(p==0):
    print("YES")
    print("A"*i)
else:
    if(x==0 and p%2!=0):
        print("NO")
    else:
        print("YES")
        if(p%2==0):
            for w in range(0,len(e)):
                if(w%2==0):
                    y=swap(y,d[e[w]][0],"A")
                else:
                    y=swap(y,d[e[w]][0],"B")
            for b in range(0,len(y)):
                if(y[b]=="0"):
                    y=swap(y,b,"A")
            print(y)
        else:
            for w in range(0,len(e)):
                if(w%2==0):
                    y=swap(y,d[e[w]][0],"A")
                else:
                    y=swap(y,d[e[w]][0],"B")
            y=swap(y,d[r][-1],"B")
            for b in range(0,len(y)):
                if(y[b]=="0"):
                    y=swap(y,b,"A")
            print(y)