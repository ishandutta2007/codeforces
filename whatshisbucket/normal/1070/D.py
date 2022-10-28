n,k=map(int,input().split())
a=list(map(int,input().split()))
bags=0
carry=0
for i in range(n):
    new=a[i]
    if carry==0:
        bags+=new//k
        carry=new%k
    else:
        bags+=1
        new-=(k-carry)
        if new<=0:
            carry=0
        else:
            bags+=new//k
            carry=new%k
if carry>0:
    bags+=1
print(bags)