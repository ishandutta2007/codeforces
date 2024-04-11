p=998244353
n=int(input())
facs=[1]
for i in range(1,n):
    facs.append(facs[-1]*i%p)
graph=[0]*n
for i in range(n-1):
    u,v=map(int,input().split())
    graph[u-1]+=1
    graph[v-1]+=1
prod=n
for i in range(n):
    prod=prod*facs[graph[i]]%p
print(prod)