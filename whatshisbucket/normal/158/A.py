n,k=map(int,input().split())
a=list(map(int,input().split()))
good=a[k-1]
pro=0
for guy in a:
    if guy>=good and guy>0:
        pro+=1
print(pro)