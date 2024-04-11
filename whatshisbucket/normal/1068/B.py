b=int(input())
factors=0
for i in range(1,int(b**.5-0.1)+1):
    if b%i==0:
        factors+=1
factors*=2
if round(b**.5)**2==b:
    factors+=1
print(factors)