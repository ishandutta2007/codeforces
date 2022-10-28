n=int(input())
l=list(map(int,input().split()))
r=list(map(int,input().split()))
candies=[]
for i in range(n):
    candies.append(n-l[i]-r[i])
left=[]
for i in range(n):
    guys=0
    for j in range(i):
        if candies[j]>candies[i]:
            guys+=1
    left.append(guys)
right=[]
for i in range(n):
    guys=0
    for j in range(i,n):
        if candies[j]>candies[i]:
            guys+=1
    right.append(guys)
if left==l and right==r:
    print("YES")
    candiesstr=""
    for i in range(n):
        candiesstr+=str(candies[i])+" "
    print(candiesstr[:len(candiesstr)-1])
else:
    print("NO")