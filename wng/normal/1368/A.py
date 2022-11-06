
t=int(input())
for nt in range(t):
    a,b,n=[int(k) for k in input().strip().split(" ")]
    k=0
    if b<a:
        a,b=b,a
    while b<=n:
        a+=b
        if b<a:
            a,b=b,a
        k+=1
    print(k)