from sys import stdout
from random import randint
n,k=[int(k) for k in raw_input().split(" ")]

nmin,nmax=1,n
tr=max(1,6*k)
nbq=0
while True and nbq<=4500:
    isok=True
    while nmax-nmin>tr:
        mid=(nmax+nmin)/2
        print nmin,mid
        nbq+=1
        stdout.flush()
        r=raw_input()
        if r=="Bad" or nbq==4500:
            isok=False
            break
        if r=="Yes":
            nmax=min(n,mid+k)
            nmin=max(1,nmin-k)
        else:
            nmin=max(1,mid+1-k)
            nmax=min(n,nmax+k)
            
    if not isok:
        1/0
        break
    totry=randint(nmin,nmax)#nmin+seed%(nmax-nmin+1)
    print totry,totry
    nbq+=1
    stdout.flush()
    r=raw_input()
    if r=="Bad":
        1/0
        break
    if r=="Yes":
        break
    else:
        nmin=max(1,nmin-2*k)
        nmax=min(n,nmax+2*k)