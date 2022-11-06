

t=int(input())
for nt in range(t):
    n=int(input())
    s=input()
    mr=s
    bk=1
    for k in range(2,n+1):
        p=s[k-1:]+(s[:k-1] if (n-k)%2 else s[:k-1][::-1])
        
        if (p<mr):
            mr=min(s,p)
            bk=k
    print(mr)
    print(bk)