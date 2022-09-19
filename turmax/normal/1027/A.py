i=int(input())
l="abcdefghijklmnopqrstuvwxyz"
for j in range(0,i):
    n=int(input())
    s=str(input())
    u="YES"
    for k in range(0,int((n/2)+1)):
        m1=0
        m2=0
        for t in range(0,26):
            if(l[t]==s[k]):
                m1=t
            if(l[t]==s[n-k-1]):
                m2=t
        if(abs(m1-m2)>=3 or abs(m1-m2)==1):
            u="NO"
    print(u)