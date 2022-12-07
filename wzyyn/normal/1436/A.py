import array

T=int(input())
for Tid in range(T):
    n,k=map(int,input().split())
    a=array.array('i',map(int,input().split()))
    for i in range(n):
        k-=a[i]
    if k==0:
        print('YES')
    else:
        print('NO')