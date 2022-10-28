n,t=map(int,input().split())
a=list(map(int,input().split()))
sum1=0
for i in range(n):
    sum1+=a[i]
b=t%sum1
bought=(t//sum1)*n
k=0
l=min(a)
gone=[0]*n
while b>=l:
    for i in range(n):
        if a[i]>b and gone[i]==0:
            k+=1
            gone[i]=1
            sum1-=a[i]
    bought+=(b//sum1)*(n-k)
    b=b%sum1
    if b//sum1==0:
        for i in range(n):
            if a[i]<=b:
                bought+=1
                b-=a[i]
print(bought)