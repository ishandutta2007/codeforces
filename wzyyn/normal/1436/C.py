import array

n,x,p=map(int,input().split())
s0,s1=x-1,n-x

def find(l,r,s0,s1):
    if l==r:
        return s0,s1
    mid=(l+r)//2
    #print(l,r,mid,s0,s1)
    if mid>p:
        s1-=1
    if mid<p:
        s0-=1
    if mid<=p:
        s0,s1=find(mid+1,r,s0,s1)
    else:
        s0,s1=find(l,mid,s0,s1)
    return s0,s1

s0,s1=find(0,n,s0,s1)
#print(s0,s1)
if s0<0 or s1<0:
    print(0)

else:
    ans=1
    for i in range(1,s0+s1+1):
        ans=ans*i
    for i in range(1,s0+1):
        ans=ans//i
    for i in range(1,s1+1):
        ans=ans//i
    for i in range(1,(x-1)+1):
        ans=ans*i
    for i in range(1,(n-x)+1):
        ans=ans*i
    print(ans%1000000007)