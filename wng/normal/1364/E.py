

from random import randint,shuffle
import sys

nbq=0

def queryserver(i,j):
    print("?",i,j)
    sys.stdout.flush()
    return int(input())

hidden=None

def query(i,j):
    global nbq
    nbq+=1
    if hidden is not None:
        return hidden[i-1]|hidden[j-1] 
    else:
        return queryserver(i,j)
    
def genhidden(n):
    ls = list(range(n))
    shuffle(ls)
    return ls

def countbits(n):
    res=0
    while n:
        if n%2:
            res+=1
        n>>=1
    return res

def determine_value(cd,basev=None):
    howmuch=20
    res=basev
    for i in range(howmuch):
        z=randint(1,n)
        while z==cd:
            z=randint(1,n)
        repq=(query(cd,z))
        res = repq if res is None else (repq&res)
    return res


n=int(input())
mnbq=0
for sim in range(1):
    #hidden=genhidden(n)
    while True:
        ri=rj=0
        while ri==rj:
            ri,rj=[randint(1,n) for i in range(2)]
        rep=query(ri,rj)
        if (countbits(rep)<=7):
            break
    #on commence avec ri

    cd=ri
    tv=determine_value(ri)
    pcd=set([cd])
    for i in range(1,n+1):
        if i not in pcd:
            if query(cd,i) <= tv:
                cd=i
                pcd.add(i)
                tv=determine_value(cd)
                if tv==0:
                    break

    res=[0]*n
    for i in range(1,n+1):
        if i!=cd:
            res[i-1]=query(i,cd)

    print(" ".join(["!"] + [str(k) for k in res]))
    if hidden is not None:
        assert(hidden==res)
    #print(nbq)
    mnbq=max(mnbq,nbq)
    nbq=0
    sys.stdout.flush()
#print(mnbq)