
t=int(input())
for nt in range(t):
    s=input()
    s2=input()
    ss=sorted(s)
    n=len(s)
    n2=len(s2)
    isok=False
    for i in range(n2-n+1):
        if sorted(s2[i:i+n])==ss:
            isok=True
            break
    if isok:
        print("YES")
    else:
        print("NO")