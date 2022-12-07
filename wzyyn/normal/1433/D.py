import array
T=int(input())
for Tid in range(T):
    n=int(input())
    a=array.array('i',map(int,input().split()))
    f1,f2=0,-1
    for i in range(n):
        if a[i]!=a[0]:
            f2=i
    if (f2==-1):
        print("NO")
    else:
        print("YES")
        print(0+1,f2+1)
        for i in range(1,n):
            if i!=f2:
                if a[i]!=a[0]:
                    print(0+1,i+1)
                else:
                    print(f2+1,i+1)