import array
T=int(input())
for Tid in range(T):
    n=int(input())
    a=array.array('i',map(int,input().split()))
    s=0
    a=sorted(a)
    for i in range(n):
        s+=a[i]
    if s==0:
        print('NO')
    else:
        print('YES')
        if s<0:
            for i in range(n):
                print(a[i],end=' ')
        else:
            for i in range(n-1,-1,-1):
                print(a[i],end=' ')
        print()