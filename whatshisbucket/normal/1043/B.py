n=int(input())
a=list(map(int,input().split()))
diff=[a[0]]
for i in range(n-1):
    diff.append(a[i+1]-a[i])
out=""
count=0
for i in range(1,n+1):
    good=True
    for j in range(n-i):
        if diff[j]!=diff[j+i]:
            good=False
    if good:
        count+=1
        out+=str(i)+" "
print(count)
print(out[:-1])