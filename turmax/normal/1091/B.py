n=int(input())
sum1=0
sum2=0
for i in range(2*n):
    a,b=map(int,input().split())
    sum1+=a 
    sum2+=b 
print(int(sum1/n),int(sum2/n))