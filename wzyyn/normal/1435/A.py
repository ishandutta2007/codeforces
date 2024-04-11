import array
T=int(input())
for Tid in range(T):
    n=int(input())
    a=array.array('i',map(int,input().split()))
    for i in range(0,n,2):
        print(-a[i+1],a[i],end=' ')
    print()