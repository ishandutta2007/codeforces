n,k=map(int,input().split())
factors=[]
for i in range(1,round(n**0.5)+1):
    if n%i==0:
        factors+=[i,n//i]
factors.sort()
big=None
for i in range(len(factors)):
    if factors[i]>=k:
        big=factors[i-1]
        break
if big==None:
    big=factors[-1]
print(n//big*k+big)