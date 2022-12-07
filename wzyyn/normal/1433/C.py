import array
T=int(input())
for Tid in range(T):
    n=int(input())
    a=array.array('i',map(int,input().split()))
    f1,f2=0,-1
    for i in range(n):
        if a[i]>a[f1]:
            f1=i
    for i in range(n):
        if a[i]==a[f1]:
            if i!=0 and a[i-1]<a[i]:
                f2=i+1
            if i!=n-1 and a[i+1]<a[i]:
                f2=i+1
    print(f2)