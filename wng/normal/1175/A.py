t=[int(k) for k in input().split(" ")][0]

for nbt in range(t):
    n,k=[int(k) for k in input().split(" ")]
    res=0
    while n!=0:
        res+=n%k
        n-=n%k
        if n>=k:
            n//=k
            res+=1
    print(res)