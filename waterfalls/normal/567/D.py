n,k,a = map(int,input().split())
m = int(input())
x = [int(y) for y in input().split()]

def check(K):
    used = [0]*(n+1)
    for i in range(K):
        used[x[i]] = 1
    for i in range(1,n+1):
        used[i]+=used[i-1]
    have = 0
    i = a
    while i<n+1:
        if used[i]-used[i-a]==0:
            have+=1
            i+=a
        i+=1
    return have>=k

if check(m):
    print(-1)
else:
    low = -1
    high = m
    while high-low>1:
        if check((low+high+1)//2):
            low = (low+high+1)//2
        else:
            high = (low+high+1)//2
    print(high)