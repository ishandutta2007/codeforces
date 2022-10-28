n=int(input())
a=list(map(int,input().split()))
curr=0
two=0
tri=0
while curr<n:
    tri+=a[curr]//3
    a[curr]%=3
    while two<n-1 and (a[two]<2 or two<=curr):
        two+=1
    if a[curr]==1:
        if a[two]>=2 and two>curr:
            a[curr]-=1
            a[two]-=2
            tri+=1
    elif a[curr]==2:
        if a[two]>=2 and two>curr:
            a[curr]-=1
            a[two]-=2
            tri+=1
            while two<n-1 and (a[two]<2 or two<=curr):
                two+=1
            if a[two]>=2 and two>curr:
                a[curr]-=1
                a[two]-=2
                tri+=1
    curr+=1
print(tri)