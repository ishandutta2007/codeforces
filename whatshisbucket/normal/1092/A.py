t=int(input())
alphabet="abcdefghijklmnopqrstuvwxyz"
for u in range(t):
    n,k=map(int,input().split())
    out=""
    a=n//k
    b=n%k
    for i in range(k):
        out+=alphabet[i]*a
        if i<b:
            out+=alphabet[i]
    print(out)