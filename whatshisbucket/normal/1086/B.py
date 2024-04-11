n,s=map(int,input().split())
degs=[0]*n
for i in range(n-1):
    a,b=map(int,input().split())
    degs[a-1]+=1
    degs[b-1]+=1
print(2*s/degs.count(1))