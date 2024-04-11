n=int(input())
def g(l,a):
    if a==1:
        return 0
    if l in [0,a-1]:
        return 1
    else:
        return 2
a=list(map(int,input().split()))
if sum(a)<2*n-2:
    print("NO")
else:
    leaf=a.count(1)
    notl=[]
    ls=[]
    for i in range(n):
        if a[i]!=1:
            notl.append(i)
        else:
            ls.append(i)
    if len(ls)==0:
        ls.append(notl.pop())
        ls.append(notl.pop())
    elif len(ls)==1:
        ls.append(notl.pop())
    print("YES",len(notl)+1)
    print(n-1)
    for i in range(len(notl)-1):
        print(notl[i]+1,notl[i+1]+1)
    curr=0
    curry=0
    j=len(notl)
    for i in range(len(ls)-1):
        while True:
            if curr==a[notl[curry]]-g(curry,j):
                curr=0
                curry+=1
            else:
                break
        curr+=1
        print(ls[i]+1,notl[curry]+1)        
    print(ls[-1]+1,notl[-1]+1)