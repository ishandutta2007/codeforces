n,k=map(int,input().split())
m=n//2
mini=0
maxi=n-1
while maxi>mini:
    tot=(n-m)*(n-m+1)//2-m
    if tot>k:
        mini=m+1
        m=(mini+maxi)//2
    elif tot<k:
        maxi=m-1
        m=(mini+maxi)//2
    elif tot==k:
        break
print(m)