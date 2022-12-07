T=int(input())
for Tid in range(T):
    s=input()
    n=len(s)
    s0,s1=0,0
    for i in range(n):
        if s[i:i+1]=='A':
            s1=s1+1
        else:
            if s1:
                s1-=1
            else:
                s0+=1
    print((s0%2)+s1)