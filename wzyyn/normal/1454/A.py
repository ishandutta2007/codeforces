T=int(input())
for i in range(T):
    n=int(input())
    for i in range(n-1):
        print((i+1)%n+1,end=' ')
    print(1)