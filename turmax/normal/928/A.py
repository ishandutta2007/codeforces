s=str(input().lower())
n=int(input())
z="Yes"
for i in range(0,n):
    t=str(input().lower())
    m=0
    for j in range(0,len(t)):
        if(len(t)!=len(s)):
            m=1
        else:
            if((t[j]!=s[j])):
                if((t[j] not in ["0","o"]) or (s[j] not in ["0","o"])):
                    if((t[j] not in ["1","i","l"]) or (s[j] not in ["1","i","l"])):
                        m=1
    if(m==0):
        z="No"
print(z)