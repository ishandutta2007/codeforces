n,m=map(int,input().split())
k=n%m
j=(n-k)//m
total=0
actual=0
for i in range(1,m+1):
    for l in range(1,m+1):
        if (i**2+l**2)%m==0:
            total+=1
            if 0<i<=k and 0<l<=k:
                actual+=(j+1)**2
            elif 0<i<=k or 0<l<=k:
                actual+=j*(j+1)
            else:
                actual+=j**2
if k==0:
    print(j**2*total)
else:
    print(actual)