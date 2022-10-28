n,I=map(int,input().split())
a=list(map(int,input().split()))
diff=len(set(a))
k=(8*I)//n
K=2**k
if diff<K:
    print(0)
else:
    a.sort()
    ind=0
    curr=-1
    changes=[]
    for i in range(n):
        if a[ind]!=curr:
            changes.append(ind)
            curr=a[ind]
            ind+=1
        else:
            ind+=1
    b=a[::-1]
    ind=0
    curr=-1
    changes1=[]
    for i in range(n):
        if b[ind]!=curr:
            changes1.append(ind)
            curr=b[ind]
            ind+=1
        else:
            ind+=1
    mini=10**15
    for i in range(diff-K+1):
        mini=min(mini,changes[i]+changes1[diff-K-i])
    print(mini)