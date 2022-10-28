n=int(input())
a=list(map(int,input().split()))
costs=[]
for i in range(n):
    tot=0
    for j in range(n):
        tot+=4*a[j]*max((i,j))
    costs.append(tot)
print(min(costs))