n=int(input())
a=list(map(int,input().split()))
print(n)
print(1,n,3*n)
for i in range(n-1):
    print(2,i+1,a[i]+3*n-i)