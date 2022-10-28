n=int(input())
a=list(map(int,input().split()))
big=max(a)
sumi=sum(a)
good=[]
k=a.count(big)
for i in range(n):
    if 2*big==sumi-a[i]:
        if k==1:
            if a[i]!=big:
                good.append(i+1)
        else:
            good.append(i+1)
if k==1:
    big=max(a[0],a[1])
    second=min(a[0],a[1])
    for i in range(n-2):
        if a[i+2]>big:
            second=big
            big=a[i+2]
        elif a[i+2]>second:
            second=a[i+2]
    if 2*second==sumi-big:
        good.append(a.index(big)+1)
out=""
for guy in good:
    out+=str(guy)+" "
print(len(good))
print(out)