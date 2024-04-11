def double(a):
    b=len(a)
    c=a[:]
    for i in range(b):
        c[i]*=2
    return(c)
def getseq(n):
    if n==1:
        return [1]
    elif n==3:
        return [1,1,3]
    else:
        return [1]*(n-n//2)+double(getseq(n//2))
n=int(input())
a=getseq(n)
out=""
for guy in a:
    out+=str(guy)+" "
print(out)