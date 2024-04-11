n=int(raw_input())
m=int(raw_input())
a=[]
for i in range(n):
    a+=[int(raw_input())]

maxk=max(a)+m
maxwithoutchanging=max(a)*n-sum(a)

if m<=maxwithoutchanging:
    mink=max(a)
else:
    m-=maxwithoutchanging
    mink=max(a)+(m-1)/n+1

print mink,maxk