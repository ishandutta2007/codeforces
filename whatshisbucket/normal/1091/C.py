n=int(input())
smallfac=[]
bigfac=[]
for i in range(1,int(n**0.5+0.99999999)):
    if n%i==0:
        smallfac.append(i)
        bigfac.append(n//i)
if round(n**0.5)==n**0.5:
    fac=smallfac+[int(n**0.5)]+bigfac[::-1]
else:
    fac=smallfac+bigfac[::-1]
out=""
for guy in fac[::-1]:
    out+=str(guy*(((n//guy)*(n//guy-1))//2)+n//guy)+" "
print(out)