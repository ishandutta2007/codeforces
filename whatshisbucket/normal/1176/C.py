def rank(x):
    if x==4:
        return 0
    if x==8:
        return 1
    if x==15:
        return 2
    if x==16:
        return 3
    if x==23:
        return 4
    return 5
n=int(input())
a=list(map(int,input().split()))
curr=[0,0,0,0,0,0]
for guy in a:
    b=rank(guy)
    if b==0:
        curr[b]+=1
    else:
        if curr[b-1]>curr[b]:
            curr[b]+=1
print(n-6*min(curr))