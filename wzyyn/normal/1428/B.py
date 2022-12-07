T=int(input())
for Tid in range(T):
    n=int(input())
    s=input()
    f0=f1=1
    for i in range(n):
        if s[i]=='<': f0=0
        if s[i]=='>': f1=0
    if f0 or f1:
        print(n)
    else:
        ans=0
        for i in range(n):
            if s[i]=='-':
                ans=ans+2
                if i!=0 and s[i-1]=='-':
                    ans=ans-1
        if s[0]=='-' and s[n-1]=='-':
            ans=ans-1
        print(ans)